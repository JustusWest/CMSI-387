#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sum(int num_array[25], int size) {
  int total = 0;
  for (int i = 0; i < size; i++) {
    total = total + num_array[i];
  }
  return total;
}

double average(int sum, int size) { 
  return (sum / (double) size); 
  }

char* concatinate(int my_numbs[25], int size) {
  char* result = malloc(100);
  result[0] = '\0';

  for (int i = 0; i < size; i++) {
    char* s_version = malloc(20);
    sprintf(s_version, "%d", my_numbs[i]);
    strcat(result, s_version);
    free(s_version);
  }
  return result;
  free(result);
}

int sevens(char* string_version) { 
    int length =  strlen(string_version);
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (string_version[i] == '7') {
          count++;
        }
    }
    return count;
}

int main() {
  int my_numbs[25];
  int i = 0;

  // Infinite loop to receive numbers until "-9999" is input
  while (1) {
    printf("Please enter an integer: ");
    char input[25];
    char* number = gets(input);
    int i_value = atoi(number);
    // printf("number is %d\n", i_value);
    if (i_value == -9999) {
      break;
    }
    my_numbs[i] = i_value;
    i++;
  }
  int array_sum = sum(my_numbs, i);
  char* cat_string = concatinate(my_numbs, i);

  printf("Sum is %d\n", array_sum);
  printf("Average is %f\n", average(array_sum, i));
  printf("String is %s\n", cat_string);
  printf("Sevens is %d\n", sevens(cat_string));
}
