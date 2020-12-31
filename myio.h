#ifndef SHELL_IO_H_
#define SHELL_IO_H_
#include <cstdio>
char* myreadline();
char **mydealstring(char* command);
void Print(char *s);
void Flush();
void Err(const char *s);
#endif