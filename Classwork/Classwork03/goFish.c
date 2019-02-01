#include <stdio.h>
#include <stdlib.h>

int sum(int num_array[25], int size) {
    int total = 0;
    for (int i = 0; i < size; i++) {
        total = total + num_array[i];
    }
    return total;
}

int main() {
    int my_numbs[25];
    int i = 0;

    while (1) {
        char input[25];
        char *number = gets(input);
        int i_value = atoi(number);
        printf("number is %d \n", i_value);
        if (i_value == -9999) { break; }
        my_numbs[i] = i_value;
        i++;
    }

    printf("Sum is %d", sum(my_numbs, i));
}
