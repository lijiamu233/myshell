#include "builtin.h"
#include "../myio.h"
#include <cstdio>
#include <cstdlib>

int myecho(char **argv)
{
    for(int i = 1; argv[i]; i++,Print(" "))
        Print(argv[i]);
    Print("\n");
    return 0;
}