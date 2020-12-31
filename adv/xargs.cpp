#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
bool readin(char** buf, char delim)
{
    if(*buf != nullptr) 
        free(*buf), *buf = nullptr;
    int len = 1024;
    char* buffer = (char *)malloc(sizeof(char) * len);
    int tot = 0,ch;
    while((ch = getchar()) != EOF)
    {
        if(tot == len)
        {
            len += 1024;
            buffer = (char*)realloc(buffer, sizeof(char) * len);
        }
        if(ch == delim)
            {
                buffer[tot++] = ' ';
                continue;
            }  
        buffer[tot++] = ch;
    }
    buffer[tot] = 0;
    *buf = buffer;
    return tot;
}
int main(int argc, char** argv)
{
    char delim = '\n';
    int ret = 0;
    int position = 1;
    if(argc > 1)
        if(!strcmp(argv[1], "-d"))
        {
            if(!argv[2])
            {
                fprintf(stderr, "xargs: missing delim\n");
                exit(1);
            }
            if(!strcmp(argv[2], "\n"))
                delim = '\n';
            else if(!strcmp(argv[2], "\t"))
                delim = '\t';
            else if (strlen(argv[2]) != 1)
            {
                fprintf(stderr, "invaild delim\n");
                exit(1);
            }
            else
                delim = argv[2][0];
            position = 3;
        }
    //argv = (char **)realloc(argv, sizeof(char *) * (argc + 3));
    char** new_argv = (char**)malloc(sizeof(char**) * (argc + 3));
    memcpy(new_argv, argv, sizeof(char*)*argc);
    new_argv[argc] = new_argv[argc+1] = 0;
    argv = new_argv;
    if(!argv[position])
    {
        argv[argc++] = "echo";
        argv[argc] = argv[argc+1] = 0;
    }

    while (readin(argv + argc, delim))
    {
        int sta = 0;
        pid_t pid = fork();
        if (pid == 0)
        {
            sta = 0;
            if (execvp(argv[position], argv+position) == -1)
            {
                perror("xargs");
                sta = 1;
            }
            exit(sta);
        }
        else if (pid < 0)
            perror("xargs: fork error");
        else
        {
            pid_t wpid;
            do {
                wpid = waitpid(pid, &sta, WUNTRACED);
            } while (!WIFEXITED(sta) && !WIFSIGNALED(sta));
        }
        ret |= sta;
    }
    return ret;    
}