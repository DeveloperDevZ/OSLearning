#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    printf("hello world (pid:%d)\n", (int)getpid());
    int rc = fork();
    if (rc < 0)
    { // If fork fails, this code exits
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0) // This is the child process
    {
        printf("hello, I am child (pid: %d)\n", (int)getpid());
    }
    else
    {
        printf("hello, I am a parent of %d (pid: %d)\n", rc, (int)getpid());
    }
    return 0;
}