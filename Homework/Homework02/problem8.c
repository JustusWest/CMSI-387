#include <stdio.h>
#include <time.h>

int main() {
  clock_t start_t, end_t, total_t;

  char big_array[1000000];

  for (int i = 0; i < 1000000; i += 4096) {
    start_t = clock();
    printf("%c", big_array[i]);
    end_t = clock();
    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("Total time taken by CPU: %f\n", total_t);
  }

  return (0);
}