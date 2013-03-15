#include <stdio.h>
 
int main ( int argc, char *argv[] ) {
    
    // Opens the file passed as an argument as read-only
    FILE *f = fopen(argv[1], "r");
 
    if (f == NULL) {
        printf( "There was a problem opening the file\n" );
    }
    else {
        char character;
        
        // Print character by character
        // until the end of the file is reached.
        while  ((character = fgetc(f)) != EOF) {

            printf("%c", character);
        }

        // Closes the file.
        fclose(f);
    }
}