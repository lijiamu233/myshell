#include "builtin.h"

#include <unistd.h>
#include <cstdio>
#include <errno.h>

int mycd(char **argv)
{
    if(!argv[1])
    {
        //err
        return 1;
    }
    int ret = chdir(argv[1]); 
    if(ret) perror("cd");
    return ret;
}