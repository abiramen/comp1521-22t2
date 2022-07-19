// Write a C program, write_line.c, which is given one command-line argument,
// the name of a file, and which reads a line from stdin, and writes it to the
// specified file; if the file exists, it should be overwritten (rather than appended).
//


#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    
    if (argc != 2) {
        printf("usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // open the file for writing
    // this will overwrite the file if it already exists.
    FILE *stream = fopen(argv[1], "w");

    if (stream == NULL) {
        perror(argv[1]);
        return 1;
    }

    // read in bytes from stdin
    int c;
    while ((c = getchar()) != EOF || c != '\n') {
        // write the byte to the file
        fputc(c, stream);
    }
    fputc('\n', stream);

    fclose(stream);

}

// What change would we make if we wanted to append to a file rather than
// overwrite it?
