#include <stdio.h>
#include <ctype.h>
#include <pwd.h>
int main() {
    FILE *input = fopen("/etc/passwd", "r");
    int currentChar;
    currentChar = fgetc(input);
    while(EOF != currentChar){
        printf("%c", toupper(currentChar));
        currentChar = fgetc(input);
    }
    fclose(input);
}
