#include <cstdio>
#include <cstring>

#include <dirent.h>
#include <libgen.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
bool JudgeDir(char* dir)
{
    struct stat buf;
    stat(dir, &buf);
    if((buf.st_mode & __S_IFMT) == __S_IFDIR)
        return true;
    return false;
}
int move(char* from, char* to)
{
    char copyto[1024];strcpy(copyto, to);
    if(access(to, F_OK) != -1 && JudgeDir(to))
    {
        int n = strlen(copyto);
        if(copyto[n-1] != '/') copyto[n++] = '/';
        copyto[n] = 0;
        strcat(copyto, basename(from));
    }
    int err = rename(from, copyto);
    if(err)
        fprintf(stderr, "mv: %s\n", strerror(errno));
    return err;
}
int main(int argc, char** argv)
{
    if(argc > 1)
    {
        if (!JudgeDir(argv[argc - 1]) && argc > 3)
        {
            fprintf(stderr, "mv: errors occured\n");
            return 1;
        }
        else for (int i = 1; i < argc - 1; i++)
        move(argv[i], argv[argc-1]);
        return 0;
    }
    fprintf(stderr, "mv: missing arguments");
    return 1;
}