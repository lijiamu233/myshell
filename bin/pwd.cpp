#include "builtin.h"
#include "../myio.h"

#include <cstdio>
#include <unistd.h>
#include <cstring>

int mypwd(char **argv)
{
    char* s = get_current_dir_name();
    Print(s);
    Print("\n");
    return 0;
}