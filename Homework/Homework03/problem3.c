#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <ctype.h>
int main() {
    FILE *input = fopen("./beeMovie.txt", "r+");
    FILE *output = fopen("./beeMovieUpper.txt", "w+");
    int currentChar;
    currentChar = fgetc(input);
    while(EOF != currentChar){
        fputc(toupper(currentChar), output);
        currentChar = fgetc(input);
    }
    fclose(input);
    fclose(output);
}
