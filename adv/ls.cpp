#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <ctime>

#include <sys/stat.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <unistd.h>
#include <errno.h>
#include <sys/time.h>
void Mode(mode_t mode, char* buf)
{
    char std[10] = "rwxrwxrwx";
    for(int i = 0; i < 9; i++)
        buf[i] = (mode & (1 << (8 - i))) ? std[i] : '-';
    buf[9]='\0';
}
bool isl;
void Out(dirent* file, const char* path)
{
    if(!isl)
    {
        printf("%s ", file->d_name);
        return;
    }
    char type = '-';
    switch (file->d_type)
    {
        case DT_DIR:
            type = 'd';
            break;
        case DT_BLK:
            type = 'b';
            break;
        case DT_LNK:
            type = 'l';
            break;
        case DT_SOCK:
            type = 'c';
            break;
    }
    printf("%c",type);
    struct stat buf;
    char Truepath[1024];
    strcpy(Truepath, path);
    int n = strlen(Truepath);
    if(Truepath[n-1] != '/')
        Truepath[n++] = '/';
    Truepath[n] = 0;
    strcat(Truepath, file->d_name);
    errno = 0;
    stat(Truepath, &buf);
    if(errno) 
        perror("ls"), errno = 0;
    char msg[105];
    Mode(buf.st_mode, msg);
    printf("%s", msg);
    passwd *user = getpwuid(buf.st_uid);
    group *Group = getgrgid(buf.st_gid);
    printf(" %3ld %s %s %8ld", buf.st_nlink, user->pw_name, Group->gr_name, buf.st_size);
    ctime_r(&buf.st_mtim.tv_sec, msg);
    n = strlen(msg);
    msg[n-1] = 0;
    printf(" %s %s\n", msg, file->d_name);
}
bool more, first;
int ls(const char* path)
{
    if (first) printf("\n");
    if (more)
        printf("%s:\n", path);
    DIR* dir = opendir(path);
    dirent* file;
    if (!dir) {
        fprintf(stderr, "%s: %s\n", path, strerror(errno));
        return 1;
    }
    while ((file = readdir(dir)))
    {
        if (file->d_name[0] == '.') continue;
        Out(file, path);
    }
    if(!isl) putchar('\n');
    closedir(dir);
    return 0;
}
int main(int argc, char** argv)
{
    int opt, ret = 0;
    while ((opt = getopt(argc, argv, "l")) != -1)
    {
        if(opt == 'l')
            isl = true;
        else
            fprintf(stderr, "wrong option\n", opt);
    }
    if(argc - optind > 1) more = true;
        for (int i = optind; i < argc; i++)
        {
            ls(argv[i]);
            first = true;
        }
    if(!first)
        ret |= ls(".");
    return ret;
}