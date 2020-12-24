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

void cat(int f)
{
    char buf[1024];
    int len = 0;
    while (len = read(f, buf, 1024))
    {
        if (len <= 0) break;
        write(STDOUT_FILENO, buf, len);
    }
}
int main(int argc, char** argv)
{
    if (argc == 1)
        cat(STDIN_FILENO);
    else
    {
        for (int i = 1; i < argc; i++)
        {
            int f = open(argv[i], O_RDONLY);
            if (f > 0)
            {
                cat(f);
                close(f);
            }
            else
                perror("cat");
        }
    }
    return 0;
}