#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
int main (int argc, char **argv)
{
 int i = 0;
 long sum;
 int pid;
 int status, ret;
 char *myargs [] = { NULL };
 char *myenv [] = { NULL };
 printf ("Parent: Hello, World!\n");
 pid = fork ();
 if (pid == 0) {
 execve ("child", myargs, myenv);
 }
 printf ("Parent: Waiting for Child to complete.\n");
 if ((ret = waitpid (pid, &status, 0)) == -1)
 printf ("parent:error\n");
 if (ret == pid)
 printf ("Parent: Child process waited for.\n");
}