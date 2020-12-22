#include <cstdio>
#include <cstdlib>
#include <readline/readline.h>
#include <readline/history.h>
#include <cstring>
#include "myio.h"

#define DELIM " \t\r\n\a"
#define BUF_SIZE 1024
#define FD_STDIN 0
#define FD_STDOUT 1
#define FD_STDERR 2
FILE* stream[3];
char* myreadline(FILE* in)
{
    char *rd = nullptr;
    rd = readline("$ ");
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

        token = strtok(command, DELIM); 
    }
    tokens[total] = nullptr;
    return tokens;
}

void Print(char *s)
{
    fprintf(stream[FD_STDOUT], "%s", s);
}

void Flush(char *s)
{
    fflush(stream[FD_STDOUT]);
}

void Err(char *s)
{
    fprintf(stream[FD_STDERR], "%s", s);
}
