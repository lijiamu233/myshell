#include "builtin.h"
#include "../myio.h"
#include <unistd.h>
#include <cstdio>
#include <errno.h>

int mycd(char **argv)
{
    if(!argv[1])
    {
        Err("cd:require more arguments\n");
        return 1;
    }
    int ret = chdir(argv[1]); 
    if(ret) perror("cd");
    return ret;
}