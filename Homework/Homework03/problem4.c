#include <ctype.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <time.h>

void printTime(clock_t t) {
    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC;
    printf("Finished in %f seconds\n", time_taken);
}

int main(int argc, char *argv[]) {
    clock_t t;
    int fd;
    struct stat s;
    int status;
    size_t size;
    const char *mapped;
    int i;
    t = clock();
    if (!argv[1]) {
        printf("Must provide file name to search for x's\n");
        return 2;
    }
    const char *fname = argv[1];

    fd = open(fname, O_RDONLY);

    status = fstat(fd, &s);
    size = s.st_size;

    mapped = mmap(0, size, PROT_READ, MAP_PRIVATE, fd, 0);

    for (i = 0; i < size; i++) {
        char c = mapped[i];
        if (c == 'x' || c == 'X') {
            printf("Found x in %s at character %d\n", fname, i);
            printTime(t);
            return 0;
        }
    }
    printf("No x found in file %s\n", fname);
    printTime(t);
    return 1;
}
