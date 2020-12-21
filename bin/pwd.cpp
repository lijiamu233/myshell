#include "builtin.h"

#include <cstdio>
#include <unistd.h>
#include <cstring>

int mypwd(char **argv)
{
    get_current_dir_name();
    //printf()
    return 0;
}