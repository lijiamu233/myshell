#include <unistd.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sys/stat.h>
#include <sys/types.h>
#include <libgen.h>
#include <dirent.h>

bool JudgeDir(char* dir)
{
    struct stat buf;
    stat(dir, &buf);
    if((buf.st_mode & __S_IFMT) == __S_IFDIR)
        return true;
    return false;
}
int Link(char* origin, char* target, bool flag)
{
    //puts(origin);
    //puts(target);
    char copytarget[1024];
    int ret = 0;
    strcpy(copytarget, target);
    if(JudgeDir(target))
    {
        int n = strlen(copytarget);
        if (copytarget[n-1] != '/')
        copytarget[n++] = '/';
        copytarget[n] = 0;
        strcat(copytarget, basename(origin));
    }
    if(flag)
        ret |= symlink(origin, copytarget);
    else
        ret |= link(origin, copytarget);
    return ret;
}
int main(int argc, char **argv)
{
    bool soft = false;
    int ret = 0;
    for (int arg;(arg = getopt(argc, argv, "s")) != -1;)
    {
        switch (arg)
        {
            case 's':
                soft = true;
                break;
            default:
                break;
        }
    }
    if(argc - optind < 1)
    {
        fprintf(stderr, "ln: missing arguments\n");
        return 1;
    }
    else if(argc - optind > 2)
    {
        if (access(argv[argc-1], F_OK) != -1 && !JudgeDir(argv[argc-1]))
        {
            fprintf(stderr, "ln: target file has existed\n");
            return 1;
        }   
    }
    for(int i = optind; i < argc - 1; i++)
        ret |= Link(argv[i], argv[argc-1], soft);
    return ret;
}