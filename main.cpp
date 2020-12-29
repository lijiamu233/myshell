#include <cstdio>
#include <cstdlib>
#include <signal.h>
#include <unistd.h>

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
    if(access(".myshellrc", F_OK) == -1)
        puts("myshell: .rc not find");
    else
    {
        FILE* rc = fopen(".myshellrc", "r");
        char file[1024];
        while (fgets(file, 1024, rc) != nullptr)
        {
            char** rcfile = mydealstring(file);
            myexec_bin(rcfile, -1);
            free(rcfile);
        }
        fclose(rc);
    }
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
//export PATH=/home/lijiamu/下载/Lab_newbie_task/myshell/build/bin:/usr/local/bin:/usr/bin:/bin