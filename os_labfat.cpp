#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main(void){

    pid_t retVal;

    retVal = fork();

    if(retVal > 0){
        int i = 0;
        while(i++ < 5){
            printf("in the parent process.\n");
            sleep(1);
        }
        //kill the child process
        kill(retVal, SIGKILL);

    } else if (retVal == 0){
        int i = 0;
        //will not ever get to 15, because
        //the parent process will kill it
        while(i++ < 15){
            printf("In the child process.\n");
            sleep(1);
        }
    } else {
        //something bad happened.
        printf("Something bad happened.");
        exit(EXIT_FAILURE);
    }

    return 0;

}

