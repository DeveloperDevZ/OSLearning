#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h> 
#include <string.h>

int main(int argc, char *argv[]){
    int fileDirectory = open("hw5p2.txt", O_RDWR | O_CREAT);
   
    
    if(fileDirectory < 0){
        perror("File Reading Error");
    }
    int forkSystemCall = fork();

    if(forkSystemCall < 0){
        fprintf(stderr, "Forking failed");
    }else if(forkSystemCall == 0){
        printf("This is the child process with (pid: %d)\n", (int) getpid());
        const char *message2 = "This is written by the child process\n";
        write(fileDirectory, message2, strlen(message2));
    }else{
        printf("This is the parent process with (pid: %d)\n", (int) getpid());
        const char *message1 = "This is written by the parent process\n";
        write(fileDirectory, message1, strlen(message1));
    }
}