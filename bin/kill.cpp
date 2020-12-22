#include "builtin.h"
#include "../myio.h"
#include <cstdio>
#include <cstdlib>

#include <sys/types.h>
#include <signal.h>

int mykill(char **argv)
{
    if(!argv[1])
    {
        Err("kill: require more arguments\n");
        return 1;
    }
    int pid = atoi(argv[1]);
    int ret = kill(pid, SIGTERM);
    if(ret) perror("kill");
    return ret;
}