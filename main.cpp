#include <cstdio>
#include <cstdlib>
#include <signal.h>
#include "myio.h"
#include "myexec.h"
extern FILE* stream[3];
int main()
{
    stream[0] = stdin;
    stream[1] = stdout;
    stream[2] = stderr;
    signal(SIGCHLD, SIG_IGN);
    signal(SIGINT, SIG_IGN);
    do
    {
        char *rd;
        rd = myreadline(stdin);
        if(!rd) break;
        char **command = mydealstring(rd);
        int k = myexec_bin(command, -1);
        //execvp(command[0],command);
        //Print("A");
        free(rd);
        free(command);
    }while(true);
    return 0;
}