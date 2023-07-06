#include <unistd.h> //Unix standard library for System Call API implementations
#include <stdio.h>  //Standard library for input/output functionalities
#include <stdlib.h> //Memory allocation functionalities
#include <time.h>   //Contains various functions related to measuring time
#include "common.h" //Common user-defined header files to define common functions across multiple files for a project
#include "assert.h"

int main(int argc, char *argv[]) // This is used for handling command-line inputs for this project
{
    //
    int *p = malloc(sizeof(int)); // This assigns a pointer to a memory location the size of int
    // The declaration of the memory is actually not initialized
    // This would require calloc (contiguous memory allocation)
    // This contiguous block can be reassigned using realloc
    assert(p != NULL);
    // This asserts that the pointer p is not null and that memory location is assigned
    printf("(%d) memory address of p: %08x\n", getpid(), (unsigned) p);
    *p = 0; // The integer value of the pointer (dereferenced) is assigned to 0
    while (1)
    {
        sleep(1);
        *p = *p + 1;
        printf("(%d) p: %d\n", getpid(), *p); // getpid() returns the current processor ID
    }
    return 0;
}