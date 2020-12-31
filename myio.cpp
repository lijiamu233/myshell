#include <cstdio>
#include <cstdlib>
#include <readline/readline.h>
#include <readline/history.h>
#include <cstring>
#include <unistd.h>
#include <pwd.h>
#include "myio.h"
#include "bin/builtin.h"

#define DELIM " \t\r\n\a"
#define BUF_SIZE 1024
#define FD_STDIN 0
#define FD_STDOUT 1
#define FD_STDERR 2
FILE* stream[3];
char* myreadline()
{
    char *rd = nullptr;
    struct passwd *pwd = getpwuid(getuid());
    printf("\001\033[34m\002# ");
    printf("\001\033[34m\002%s",pwd->pw_name);
    printf("\001\033[37m\002 @ ");
    printf("\001\033[32m\002%s",pwd->pw_dir);
    printf("\001\033[37m\002 in ");
    printf("\001\033[33m\002%s\n",get_current_dir_name());
    rd = readline("\001\033[31m\002$ \001\33[0m\002");
    return rd;
}

char** mydealstring(char* command)
{
    int len = BUF_SIZE;
    char** tokens = (char **)malloc(sizeof(char *) * len);
    char* token;
    if(tokens == nullptr)
    {
        fprintf(stderr, "myshell: memory applicant error.\n");
        exit(1);
    }

    int total = 0;
    token = strtok(command, DELIM);
    while(token != nullptr)
    {
        tokens[total++] = token;
        //fprintf(stderr, "myshell: loop loop error.\n");
        if(total >= len)
        {
            
            len+=BUF_SIZE;
            tokens = (char **)realloc(tokens, sizeof(char *) * len);
            if(tokens == nullptr)
            {
                fprintf(stderr, "myshell: memory applicant error.\n");
                exit(1);
            }
        }

        token = strtok(nullptr, DELIM); 
    }
    tokens[total] = nullptr;
    return tokens;
}

void Print(char *s)
{
    fprintf(stream[FD_STDOUT], "%s", s);
}

void Flush()
{
    fflush(stream[FD_STDOUT]);
}

void Err(const char *s)
{
    fprintf(stream[FD_STDERR], "%s", s);
}
