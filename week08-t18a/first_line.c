// Write a C program, first_line.c, which is given one command-line argument -
// the name of a file - and which prints the first line of that file to stdout.
// If given an incorrect number of arguments, or if there was an error opening
// the file, it should print a suitable error message.
//
// A line may be of any size.

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("usage: %s <filename>\n", argv[0]);
        return 1;
        
    }

    FILE *stream = fopen(argv[1], "r");
    if (stream == NULL) {
        // something went wrong
        // we need to handle an error
        perror(argv[1]);
        return 1;
    }

    // 256 values  in a byte
    // + 1 more value for EOF

    int c;

    while ((c = fgetc(stream)) != EOF && c != '\n') { 
        putchar(c);
    }
    putchar('\n');


    fclose(stream);

    return 0;
}


    // fputc - write characters to files
    // putchar - write specificically to stdout
    // fgetc - read a character from a file
    // getchar - read a character specifically from stdin



    // fputs - writes a string to a file
    // fgets - reads a string from a file
    // puts - writes a string specifically to stdout
    // gets - reads a string from stdin - DO NOT USE IT

    // printf - writes a formatted string to stdout
    // fprintf - writes to any file
