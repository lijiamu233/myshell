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
int copy(char* from, char* to)
{
    if(access(from, F_OK) == -1)
    {
        fprintf(stderr, "cp: %s is not exist\n", from);
        return 1;
    }
    FILE* src = fopen(from, "rb"), *dest;
    if(access(to, F_OK) == -1)
        dest = fopen(to, "w");
    else
    {
        char copyto[1024];
        strcpy(copyto, to);
        if(JudgeDir(to))
        {
            int n = strlen(copyto);
            if (copyto[n-1] != '/')
            copyto[n++] = '/';
            copyto[n] = 0;
            strcat(copyto, basename(from));
        }
        dest = fopen(copyto, "w");
    }
    int c;
    while((c = getc(src)) != -1)
        putc(c, dest);
    fclose(src);fclose(dest);
    return 0;
}
int main(int argc, char **argv)
{
    if(argc > 2)
    {
        int ret = 0;
        if (argc > 3)
        {
            if (access(argv[argc - 1], F_OK) == -1 || !JudgeDir(argv[argc-1]))
            {
                fprintf(stderr, "cp: errors occured\n");
                return 1;
            }
            for (int i = 1; i < argc - 1; i++)
                ret |= copy(argv[i], argv[argc - 1]);
        }
        else 
            ret = copy(argv[1], argv[2]);
        return ret;
    }
    fprintf(stderr, "cp: missing arguments\n");
    return 1;
}