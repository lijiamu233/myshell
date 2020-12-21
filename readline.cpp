#include "readline.h"

char* myreadline(FILE* in)
{
    char *rd = nullptr;
    rd = readline("$ ");
    return rd;
}
