#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

static void *child(void *ignored) {
  while (1) {
    sleep(5);
    printf("Child is done sleeping 5 seconds.\n");
  }
}

int main(int argc, char *argv[]) {
  pthread_t child_thread;
  int code;
  code = pthread_create(&child_thread, NULL, child, NULL);
  if (code) {
    fprintf(stderr, "pthread_create failed with code %d\n", code);
  }

  while (1) {
    int c;
    c = getchar();
    if (c == 10) {
      pthread_cancel(child_thread);
      printf("Child thread has been killed\nPress ENTER to exit program");
      getchar();
      break;
    }
  }
  return 0;
}