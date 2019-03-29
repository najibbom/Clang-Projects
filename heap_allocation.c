/*
**
I'm trying to understand the heap a little more by applying what i've learned
This is an exercice about the allocation of heap memory.
Exercice from "Hacking The Art of Exploitation, 2nd Edition" by Jon Erickson
Thank you very much sir, i really had so much fun reading your book
and especially the "0x200 Programming" section
**
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *errocheckd_malloc(unsigned int); // Function prototype

int main(int argc, char *argv[]){
    int *int_pointer;
    char *char_pointer;
    int memeory_size;

    if(argc < 2)
        memeory_size = 50;
    else
        memeory_size = atoi(argv[1]);
    
    printf("\t[+] allocating %d bytes of memory on the heap for char_pointer\n", memeory_size);
    char_pointer = (char *) errocheckd_malloc(memeory_size);

    strcpy(char_pointer, "Allocating memory on the heap.");
    printf("char_pointer [%p] ---> '%s'\n", char_pointer, char_pointer);

    printf("\t[+] allocating 12 bytes of memory on the heap for int_pointer\n");
    int_pointer = (int *) errocheckd_malloc(12);

    *int_pointer = 31337;
    printf("int_pointer[%p] ---> %d\n", int_pointer, *int_pointer);

    printf("\t[-] freeing char_pointer's heap memory...\n");
    free(char_pointer);

    printf("\t[+] allocating 15 bytes of memory on the heap for char_pointer\n");
    char_pointer = (char *) errocheckd_malloc(15);

    strcpy(char_pointer, "Allocating new memory on the heap.");
    printf("char_pointer [%p] ---> '%s'\n", char_pointer, char_pointer);

    printf("\t[-] freeing int_pointer's heap memory...\n");
    free(int_pointer);

    printf("\t[-] freeing char_pointer's heap memory...\n");
    free(char_pointer);

    return 0;
}

void *errocheckd_malloc(unsigned int size) {
    void *pointer;
    pointer = malloc(size);

    if(pointer == NULL) {
        fprintf(stderr, "ERROR: Could not allocate heap memory");
        exit(-1);
    }
    return pointer;
}
