/*
**
This program accepts a note as a command-line argument and then adds it to the end of the file /tmp/notes.
**
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

void usage(char *program_name, char *file_name) {
    printf("Usage: %s <data to add to %s>\n", program_name, file_name);
    exit(0);
}

void fatal(char *);             // a function for fatal errors
void *ec_malloc(unsigned int);  // an error-checked malloc() wrapper

int main(int argc, char *argv[]) {

}

// Function to display error message and then exit
void fatal(char *message) {

}
// An eerror-checked malloc() wrapper function
void *ec_malloc(unsigned int size) {
    
}