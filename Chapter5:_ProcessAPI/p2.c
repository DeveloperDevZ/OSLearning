#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    printf("Hello world (pid: %d)\n", (int)getpid());
    int rc = fork();
    if (rc < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        printf("Hello, I am a child (pid: %d)\n", (int)getpid());
    }
    else
    {
        pid_t wc = wait(NULL);
        printf("Hello, I am a parent of %d (wc: %d) (pid: %d)\n", rc, wc, (int)getpid());
    }
    return 0;
}