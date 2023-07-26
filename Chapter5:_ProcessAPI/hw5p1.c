#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
    int x = 100;
    printf("Homework 5 Problem 1. (pid: %d)\n", (int) getpid());
    int forkSystemCall = fork();
    if(forkSystemCall < 0){
        fprintf(stderr, "fork failed.\n");
        exit(1);
    }else if(forkSystemCall == 0){
        printf("This is the child process with (pid: %d)\n", (int) getpid());
        x += 2;
        printf("%d\n", x);
    }else{
        pid_t status = wait(&status);
        if(WIFEXITED(status)){
            int exit_status = WEXITSTATUS(status);
            printf("Child process is complete with the exit status %d\n", exit_status);
        }
        printf("This is the parent process with (pid: %d)\n", (int) getpid());
        x += 1;
        printf("%d\n", x);
        
    }
    
}