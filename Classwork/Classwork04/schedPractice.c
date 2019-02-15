#include <stdio.h>
#include <stdlib.h>

#define t_slice = 40; 

struct Thread {
  char* name;
  int run_time;
};

int main(int argc, char* argv[]) {

  struct Thread threads[(argc - 1) / 2];

  for (int i = 1; i < argc; i += 2) {
    struct Thread test = {argv[i], atoi(argv[i + 1])};
    threads[(i - 1) / 2] = test;
  }

  return 0;
}