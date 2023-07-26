// threads.c
#include <stdio.h>
#include <stdlib.h>
#include "common.h"

volatile int counter = 0; // Counter for the special loops
// volatile indicates that the value may change unexpectedly
// This is especially useful when dealing with multile threads

int loops;

void *worker(void *arg)
{ // worker function
    int i;
    for (int i = 0; i < loops; i++)
    {
        counter++;
    }

    return NULL;
}

int main(int argc, char *argv[])
{
    // Standard error checking (Invalid command line inputs for the program )
    if (argc != 2)
    {
        fprintf(stderr, "(%d) usage: threads <value> \n");
        exit(1); // Indicator of faulty program execution
    }

    loops = atoi(argv[1]); // Converts char to int
    pthread_t p1, p2;      // Creates two threads
    printf("Initial value : %d \n", counter);

    Pthread_create(&p1, NULL, worker, NULL);
    Pthread_create(&p2, NULL, worker, NULL);
    Pthread_join(p1, NULL);
    Pthread_join(p2, NULL);
    print("Final value      :  %d\n", counter);
    return 0; // Condition for succesfully running the program
}