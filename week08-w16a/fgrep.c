// Write a C program, fgrep.c, which is given 1+ command-line arguments which is
// a string to search for.
// If there is only 1 command-line argument it should read lines from stdin and
// print them to stdout if they contain the string specified as the first 
// command line argument.
//
// If there are 2 or more command line arguments, it should treat arguments 
// after the first as filenames and print any lines they contain which contain
// the string specified as the first command line arguments.
//
// When printing lines, preface them with their line number (indexed from 1).
//
// Print a suitable error message if there are not enough arguments, or there is
// an error opening a file.
//
// Example:
// ./fgrep hello nonexistentfile.txt
//  hello: nonexistentfile.txt: No such file or directory
//
// ./fgrep test testfile.txt
// testfile.txt: 1: This is a test
//
// Assume lines are 65536 bytes at most.

#include <stdio.h>
#include <string.h>

#define MAX_LINE 65536

void search_stream(FILE *stream, char stream_name[], char search_for[]);

int main(int argc, char *argv[]) {

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <prefix> <files>\n", argv[0]);
        return 1;
    } if (argc == 2) {
        // if the user hasn't supplied any files, 
        // we'll match against stdin
        search_stream(stdin, "<stdin>", argv[1]);
    } else {

        // iterates over each of the supplied files
        for (int argument = 2; argument < argc; argument = argument + 1) {
            FILE *in = fopen(argv[argument], "r");
            
            if (in == NULL) {
                perror(argv[argument]);
                return 1;
            }

            search_stream(in, argv[argument], argv[1]);
            fclose(in);
        }

    }

    return 0;
}

void search_stream(FILE *stream, char stream_name[], char search_for[]) {
    // TODO: complete this function
    // hint: look at `strstr(3)'
    int line_number = 0;
    char buffer[MAX_LINE];
    // crucially, recall that fgets returns NULL on EOF
    // remember to check man pages!
    while (fgets(buffer, MAX_LINE, stream) != NULL) {
        if (strstr(buffer, search_for) != NULL) {
            printf("%s: %d: %s", stream_name, line_number, buffer);
        }
        line_number = line_number + 1;
    }

}