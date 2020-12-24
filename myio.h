#ifndef SHELL_IO_H_
#define SHELL_IO_H_
#include <cstdio>
char* myreadline(FILE *in);
char **mydealstring(char* command);
void Print(char *s);
void Flush(char *s);
void Err(const char *s);
#endif