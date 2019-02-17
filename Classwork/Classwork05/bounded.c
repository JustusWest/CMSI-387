#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int mutex = 1;
int full = 0;
int empty = 7; // maximum of seven messages in buffer
int x = 0;

// wait for 500ms. Sleep only accepts int seconds
struct timespec wait_time = {0.5, 500000000L};

int wait(int s) { return (--s); }

int signal(int s) { return (++s); }

void producer() {
    mutex = wait(mutex);
    full = signal(full);
    empty = wait(empty);
    x++;
    printf("\n  Producer produces the item %d", x);
    mutex = signal(mutex);
}

void consumer() {
    mutex = wait(mutex);
    full = wait(full);
    empty = signal(empty);
    printf("\n  Consumer consumes item %d", x);
    x--;
    mutex = signal(mutex);
}

static void *producer_child(void *ignored) {
    while (1) {
        if ((mutex == 1) && (full != 0)) {
            consumer();
        } else {
            printf("\nBuffer is empty!!");
        }
        nanosleep(&wait_time, &wait_time);
    }
}

static void *consumer_child(void *ignored) {
    while (1) {
        if ((mutex == 1) && (empty != 0)) {
            producer();
        } else {
            printf("\nBuffer is full!!");
        }
        nanosleep(&wait_time, &wait_time);
    }
}

int main() {

    pthread_t producer_thread;
    int code;
    code = pthread_create(&producer_thread, NULL, producer_child, NULL);
    if (code) {
        fprintf(stderr, "pthread_create failed with code %d\n", code);
    }

    pthread_t consumer_thread;
    int code2;
    code2 = pthread_create(&consumer_thread, NULL, consumer_child, NULL);
    if (code) {
        fprintf(stderr, "pthread_create failed with code %d\n", code);
    }

    sleep(10);

    return 0;
}
