#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("What is your name?\n");
  char input[25];
  char *name;
  name = gets(input);
  printf("Hello, %s\n", name);
}
