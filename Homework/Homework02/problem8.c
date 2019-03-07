#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  clock_t start_t, end_t, total_t;

  clock_t totalstart_t = clock();

  char *big_array = malloc(sizeof(char) * 10000000);
  for (int i = 0; i < 10000000; i++) {
    big_array[i] = i;
  }

  for (int i = 0; i < 2000000; i += 4096) {
    start_t = clock();
    printf("%c", big_array[i]);
    end_t = clock();
    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("Total time taken by CPU: %f\n", total_t);
  }

  clock_t totalend_t = clock();
  clock_t totaltotal_t = (double)(totalend_t - totalstart_t) / CLOCKS_PER_SEC;
  printf("Total time taken by CPU: %f\n", totaltotal_t);

  return (0);
}