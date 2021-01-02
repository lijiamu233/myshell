#include <unistd.h>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <signal.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>

void show(int f)
{
    char buf[1024];
    int len = 0;
    while (len = read(f, buf, 1024))
    {
        if (len <= 0) break;
        write(STDOUT_FILENO, buf, len);
        if(buf[len-1] != '\n')
            printf("\001\033[1m\33[7m\002%\001\33[0m\002\n");
    }
}
bool JudgeDir(char* dir)
{
    struct stat buf;
    stat(dir, &buf);
    if((buf.st_mode & __S_IFMT) == __S_IFDIR)
        return true;
    return false;
}
int main(int argc, char** argv)
{
    if (argc == 1)
        show(STDIN_FILENO);
    else
    {
        for (int i = 1; i < argc; i++)
        {
            if(JudgeDir(argv[i]))
                printf("cat: %s is a directory\n",argv[i]);
            else if(access(argv[i], F_OK) != -1)
            {
                int f = open(argv[i], O_RDONLY);
                if (f > 0)
                {
                    show(f);
                    close(f);
                }
            }
            else
                perror("cat");
        }
    }
    return 0;
}