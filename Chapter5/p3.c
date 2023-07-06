#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h> //Contains many functions for strings(strcpy, strncpy, strcat, strncat) and memory (memset, memcpy)
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
        printf("Hello, I am a child of (pid: %d)\n", (int)getpid());
        char *myargs[3];
        myargs[0] = strdup("wc");
        myargs[1] = strdup("p3.c");
        myargs[2] = NULL;
        execvp(myargs[0], myargs);
        printf("this should not print out");
    }
    else
    {
        int wc = wait(NULL);
        printf("Hello, I am a parent of %d (wc: %d) (pid: %d)\n", rc, wc, (int)getpid());
    }
    return 0;
}