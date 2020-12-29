#include "myexec.h"
#include "myio.h"
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
#include "bin/builtin.h"

pid_t ppid, wpid;
int Num_bg;
void Returnfather()
{
    kill(ppid, SIGINT);
}

pid_t Fork()
{
    pid_t pid = fork();
    if(pid < 0) Err("fork error");
    return pid;
}

int myexec_extern(char **command, bool isbg)
{
    int ret = 0;pid_t wpid;
    ppid = Fork();
    if(ppid == 0)
    {
        int ret = execvp(command[0], command);
        if(ret == -1) perror("myshell"), ret = 1;
        exit(ret);
    }
    else if(ppid < 0)
        perror("myshell");
    else
    {
        if (!isbg)
        {
            signal(SIGINT, (sighandler_t)Returnfather);
            do
            {
                wpid = waitpid(ppid, &ret, WUNTRACED);
            }while (!WIFEXITED(ret) && !WIFSIGNALED(ret));

            signal(SIGINT, SIG_IGN);
        }
        else
        {
            Num_bg++;
            printf("[%d] %d ", Num_bg, ppid);
            for (int i = 0; command[i]; i++) if(strcmp(command[i],"&")) printf("%s ", command[i]);
            putchar('\n');
        }
    }
    return ret;
}
int isbuiltin(char *cmd)
{
    char bin[6][10]={"echo", "cd", "pwd", "kill", "export","exit"};
    for(int i = 0; i < 6; i++)
        if(!strcmp(cmd,bin[i]))
            return i;
    return 6;
}
int myexec_bin(char **command,int type)
{
    signal(SIGINT, SIG_DFL);
    if(command == nullptr || command[0] == nullptr) return 0;
    int ret = 0;
    bool Canexe = true;
    errno = 0;
    //0 stdin 1 stdout -1 stderr
    int fd[2] = {type, -1};

    //if it has '&' means background
    bool isbg = false;
    for(int i = 0; command[i] != nullptr; i++)
    if(!strcmp(command[i],"&"))
    {
        isbg = true;
        command[i] == nullptr;
        for(int j = i; command[j+1] != nullptr; j++)
            command[j] = command[j+1];
        break;
    }

    //if it has '|' means a pipe
    bool ispipe = false;
    int pos_pipe = 0;
    char **pipe_prev = nullptr;
    for(int i = 0; command[i] != nullptr; i++)
        if(!strcmp(command[i],"|"))
        {
            ispipe = true;
            pos_pipe = i;
            break;
        }
    
    int Copy_stdin = dup(0);
    int Copy_stdout = dup(1);
    int fd_pipe[2] = {-1, -1};
    if(ispipe)
    {
        if(pipe(fd_pipe) == -1) perror("pipe error");
        if(dup2(fd_pipe[1], 1) == -1) perror("pipe dup error");
        command[pos_pipe] = nullptr;
        pipe_prev = command + pos_pipe + 1;
    }

    //if it has '<' || '>' means redirect

    bool isredleft = false, isredright = false;
    for(int i = 0; command[i] != nullptr; i++)
    {
        if(!strcmp(command[i], "<"))//redirect stdout (right)
        {
            isredright = true;
            if(fd[0] != -1) Canexe = false;
            else
            {
                if(command[i+1] && access(command[i+1], F_OK) == 0)
                    fd[0] = open(command[i+1], O_RDONLY);
                else Canexe = false;

            }
            command[i] = nullptr;
        }
        else if(!strcmp(command[i], ">"))//redirect stdin (left)
        {
            isredleft = true;
            if(ispipe || fd[1] != -1) Canexe = false;
            else
            {
                if(command[i+1])
                    fd[1] = open(command[i+1], O_WRONLY|O_CREAT|O_TRUNC, 777);
                else Canexe = false;
            }
            command[i] = nullptr;
        }
        if(errno) perror("redirect error");
        if(!Canexe) break;
    }

    if(Canexe)
    {
        if(fd[0] != -1) dup2(fd[0], 0);
        if(fd[1] != -1) dup2(fd[1], 1);
        int TYPE = isbuiltin(command[0]);
        switch (TYPE)
        {
            case 0:
                ret = myecho(command);
                break;
            case 1:
                ret = mycd(command);
                break;
            case 2:
                ret = mypwd(command);
                break;
            case 3:
                ret = mykill(command);
                break;
            case 4:
                ret = myexport(command);
                break;
            case 5:
                exit(0);
                break;
            case 6:
                ret = myexec_extern(command, isbg);
                break;
            default:
                break;
        }
    }
    
    if(fd_pipe[1] != -1) close(fd_pipe[1]);
    if(fd[0] != -1) close(fd[0]);
    if(fd[1] != -1) close(fd[1]);
    dup2(Copy_stdin, 0);
    dup2(Copy_stdout, 1);
    if(Canexe) myexec_bin(pipe_prev, fd_pipe[0]);
    else Err("paradoxible pipe and redirect\n");
    if(fd_pipe[0] != -1) close(fd_pipe[0]);
    signal(SIGINT, SIG_IGN);
    return ret;
}
