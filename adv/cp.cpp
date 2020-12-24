#include <cstdlib>
#include <cstdio>
#include <unistd.h>
#include <cstring>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
int main(int argc, char **argv)
{
    if(argc > 1)
    {
        for(int i = 1; i < argc; i++)
        {
            FILE* newfd = fopen(argv[i], "a+");
            fclose(newfd);
        }
        puts("\ntouch success");
        return 0;
    }
    fprintf(stderr, "touch:missing arguments\n");
    return 1;
}