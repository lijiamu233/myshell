#include <cstdlib>
#include <cstdio>
#include <unistd.h>
#include <cstring>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

int main(int argc, char **argv)
{
    if(argc > 1)
    {
        int err = 0;
        for(int i = 1; i < argc; i++)
        {
            err |= mkdir(argv[i], 0777);
            if (err)
            fprintf(stderr, "mkdir: %s\n", strerror(errno));
        }
        puts("mkdir success");
        return err;
    }
    fprintf(stderr, "mkdir:missing argument\n");
    return 1;
}