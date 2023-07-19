#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[]){
    int forkSystemCall = fork();

    if(forkSystemCall < 0){
        perror("Fork Error");
    }else if(forkSystemCall == 0){
        printf("Hello\n");
    }else{
        int status;
        pid_t wrc = waitpid(0, 1, 0);

        printf("Goodbye\n");
    }
}