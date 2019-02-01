#include <stdio.h>
#include <stdlib.h>

int main() {
  while (1) {
    int i = 0;
    char temp[25];
    char* number = gets(temp);
    int i_value = atoi(number);
    // printf("number is %d \n", i_value);
    int my_numbs[25];
    if (i_value == -9999) {
      break;
    }
    my_numbs[i] = i_value;
  }
  printf("Sum is %d", sum(my_numbs))
}

int sum(int num_array[]) {
  int total = 0;
  for (int i = 0; i < len(num_array); i++) {
    total = total + num_array[i];
  }
  return total;
}