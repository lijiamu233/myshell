#include <cstdlib>
#include <cstdio>
#include <unistd.h>
#include <cstring>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

int main(int argc, char** argv)
{
    if(argc > 1)
    {
        int ret = 0;
        for(int i = 1 ; i <  argc; i++)
        {
            int flag = unlink(argv[i]);
            if(flag)
                fprintf(stderr, "%s: %s\n", argv[i], strerror(errno));
            ret |= flag;
        }
        puts("rm success");
        return ret;
    }
    fprintf(stderr, "rm:missing arguments");
    return 1;
}