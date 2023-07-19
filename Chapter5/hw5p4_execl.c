#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]){

    int forkSystemCall = fork();

    if(forkSystemCall < 0){
        perror("Fork failed");
    }else if(forkSystemCall == 0){
        //Child process
        printf("Child process with pid: %d and a system exec() call to transfer process control", (int) getpid());
        execl("/bin/ls", "ls", "-l", (char *) NULL);  
        printf("SHOULD NOT PRINT | This section is post transfer of program control");
    }else{
        printf("This is the parent process\n");
    }   
}
