#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    /* The file descriptor. */
    int fd;
    /* Information about the file. */
    struct stat s;
    int status;
    size_t size;
    /* The file name to open. */
    /* The memory-mapped thing itself. */
    const char *mapped;
    int i;
    if (!argv[1]) {
        printf("Must provide file name to search for x's\n");
        return 2;
    }
    const char *fname = argv[1];

    /* Open the file for reading. */
    fd = open(fname, O_RDONLY);

    /* Get the size of the file. */
    status = fstat(fd, &s);
    size = s.st_size;

    /* Memory-map the file. */
    mapped = mmap(0, size, PROT_READ, MAP_PRIVATE, fd, 0);

    /* Now do something with the information. */
    for (i = 0; i < size; i++) {
        char c;

        c = mapped[i];
        // printf("%c", c);
        if (c == 'x') {
            printf("Found x in %s at character %d\n", fname, i);
            return 0;
        }
    }
    printf("No x found in file %s\n", fname);
    return 1;
}
