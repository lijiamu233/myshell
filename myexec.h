#ifndef SHELL_EXEC_H_
#define SHELL_EXEC_H_
#include <sys/types.h>
pid_t Fork();
void Returnfather();
int myexec_bin(char **command,int type);
int myexec_extern(char **command, bool isbg);
#endif