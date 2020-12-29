#include "builtin.h"
#include "../myio.h"

#include <cstring>
#include <cstdlib>
#include <unistd.h>

int myexport(char **argv)
{
    int ret = 0;
    if(!argv[1])
    {
        for(int i = 0; environ[i]; i++)
        {
            Print(environ[i]);
            Print("\n");
        }
    }
    else
    {
        for(int i = 1; argv[i]; i++)
        {
            char* position = strchr(argv[i], '=');
            if(!position)
                ret |= setenv(argv[i], "", 1);
            else
            {
                *position = 0;
                ret |= setenv(argv[i], position + 1, 1);
            }
        }
    }
    return ret;
}