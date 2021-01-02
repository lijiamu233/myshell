#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <unistd.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <dirent.h>
#include <sys/stat.h>

winsize ws;
termios oldt, newt;
void delim()
{
    puts("::::::::::::::");
}
bool JudgeDir(char* dir)
{
    struct stat buf;
    stat(dir, &buf);
    if((buf.st_mode & __S_IFMT) == __S_IFDIR)
        return true;
    return false;
}
void back()
{
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    putchar('\n');
    exit(0);
}

void Back_Old(int fd, int num)
{
    num++;
    while(num--)
    {
        char buf[2];
        int n, pos;
        while(n = read(fd, buf, 1))
        {
            if(n < 0) return;
            if (!(pos = lseek(fd, 0, SEEK_CUR))) return;
            if (pos < 2)
            {
                lseek(fd, 0, SEEK_SET);
                return;
            }
            else
                lseek(fd, -2, SEEK_CUR);
            if (buf[0] == '\n') break;
        }
    }
    lseek(fd, 2, SEEK_CUR);
}

void Create_New(int fd, int num, int total)
{
    printf("              \r");
    while (num--)
    {
        int n;
        char buf[2];
        while (n = read(fd, buf, 1))
        {
            if (n < 0) break;
            putchar(buf[0]);
            if (buf[0] == '\n') break;
        }
    }
    int pos;
    if ((pos = lseek(fd, 0, SEEK_CUR)) < total)
        printf("\001\033[1m\33[7m\002--More--(%d%%)\001\33[0m\002\r", (int)( (double)pos / total * 100 + 0.5 ) );
    fflush(stdout);
}
void mymore(int fd)
{
    int len = 0;
    int total = 0, lines = 0;
    char buf[1024];
    while (len = read(fd, buf, 1023))
    {
        if (len <= 0) break;
        total += len;
        char* p = buf;
        while(p + 1 && (p = strchr(p + 1, '\n')))
            lines++;
    }
    lseek(fd, 0, SEEK_SET);
    Create_New(fd, ws.ws_row - 1, total);
    while (lseek(fd, 0, SEEK_CUR) < total)
    {
        char c = getchar();
        switch (c)
        {
            case 'b':
            case 0x41:
                Back_Old(fd, ws.ws_row + ws.ws_row - 2);
            case 'f':
            case 0x42:
                Create_New(fd, ws.ws_row - 1, total);
                break;
            case 's':
            case '\n':
            case 'z':
            case ' ':
                Create_New(fd, 1, total);
                break;
            case 'q':
                return;
                break;
            default:
                break;
        }
    }
}
int main(int argc, char** argv)
{
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    newt.c_cc[VEOL] = 1;
    newt.c_cc[VEOF] = 2;
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
    signal(SIGINT, (sighandler_t)back);
    if(argc > 1)
    {
        if(argc == 2)
        {
            if(JudgeDir(argv[1]))
            {
                int fd = open(argv[1], O_RDONLY);
                printf("magic failed: cannot fd %d (is a directory)\n", fd);
                printf("%s\n",argv[1]);
            }
            else if(access(argv[1], F_OK) != -1)
            {
                int fd = open(argv[1], O_RDONLY);
                if (fd > 0)
                {
                    mymore(fd);
                    close(fd);
                    puts("");
                }
                else
                    perror("more");
            }
            else
                fprintf(stderr, "more: cannot open %s: the file or directory isn't existed\n",argv[1]);
        }
        else
        {
            for(int i = 1; i < argc; i++)
            {
                if(JudgeDir(argv[i]))
                {
                    int fd = open(argv[i], O_RDONLY);
                    printf("magic failed: cannot fd %d (is a directory)\n", fd);
                    delim();
                    printf("%s\n",argv[i]);
                    delim();
                    continue;
                }
                else if(access(argv[i], F_OK) != -1)
                {
                    int fd = open(argv[i], O_RDONLY);
                    delim();
                    printf("%s\n", argv[i]);
                    delim();
                    mymore(fd);
                    close(fd);
                    puts("");
                }
                else
                    fprintf(stderr, "more: cannot open %s: the file or directory isn't existed\n", argv[i]);
            }
        }
        back();
        return 0;
    }
    fprintf(stderr, "more: error using.\n");
    return 1;
}