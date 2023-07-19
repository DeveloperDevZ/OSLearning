#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
    int forkSystemCall = fork();

    if(forkSystemCall < 0){
        perror("Forking error");
    }else if(forkSystemCall == 0){
        printf("Child process");
        char *args[] = {"ls", "-l", NULL};
        execv("/bin/ls", args);
        printf("Program control has been effectively transferred");
    }else{
        printf("Parent process");
        pid_t wrc = wait(NULL);
        printf("Parent process is executed\n");
    }
}