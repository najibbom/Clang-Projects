/*
**
This program accepts a note as a command-line argument and then adds it to the end of the file /tmp/notes.
**
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "functions.h"

void usage(char *program_name, char *file_name) {
    printf("Usage: %s <data to add to %s>\n", program_name, file_name);
    exit(0);
}

void fatal(char *);             // a function for fatal errors
void *ec_malloc(unsigned int);  // an error-checked malloc() wrapper

int main(int argc, char *argv[]) {
    int fd; // file descriptor
    int userid;
    char *buffer;
    char *datafile;

    buffer = (char *) ec_malloc(100);
    datafile = (char *) ec_malloc(20);
    strcpy(datafile, "/tmp/notes");

    if(argc < 2) {                  // If there aren't any command-line arguments
        usage(argv[0], datafile);   // display usage message and exit
    }

    strcpy(buffer, argv[1]);

    printf("[DEBUG] buffer @ %p: \'%s\'\n", buffer, buffer);
    printf("[DEBUG] datafile @ %p: \'%s\'\n", datafile, datafile);

    strncat(buffer, "\n", 1);

    // Opening file
    fd = open(datafile, O_WRONLY|O_CREAT|O_APPEND, S_IRUSR|S_IWUSR);
    if(fd == -1)
        fatal("in main() while opening file");
    printf("[DEBUG] file descriptor is %d\n", fd);

    userid = getuid(); // get the real user ID

    // Writing data
    if(write(fd, &userid, 4) == -1) // Write user ID before note data
        fatal("in main() while writing userid to file");
    write(fd, "\n", 1); // Terminate line

    if(write(fd, buffer, strlen(buffer)) == -1) // Write note
        fatal("in main() while writing buffer to file");
    write(fd, "\n", 1); // Terminate line

    // Closing file
    if(close(fd) == -1)
        fatal("in main() while closing file");

    printf("Note has been saved successfully.\n");
    free(buffer);
    free(datafile);

}


