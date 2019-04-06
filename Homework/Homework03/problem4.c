#include <ctype.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    int fd;
    struct stat s;
    size_t size;
    const char *mapped;
    int i;
    if (!argv[1]) {
        printf("Must provide file name to search for x's\n");
        return 2;
    }
    const char *fname = argv[1];

    fd = open(fname, O_RDONLY);

    size = s.st_size;

    mapped = mmap(0, size, PROT_READ, MAP_PRIVATE, fd, 0);

    for (i = 0; i < size; i++) {
        char c = mapped[i];
        if (c == 'x') {
            printf("Found x in %s at character %d\n", fname, i);
            return 0;
        }
    }
    printf("No x found in file %s\n", fname);
    return 1;
}
