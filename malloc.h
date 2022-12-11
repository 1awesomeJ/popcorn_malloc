#ifndef MALLOC_H
#define MALLOC_H
#include <unistd.h>
#include <stddef.h>

/* size we'll allocated using sbrk */
#define ALLOC_SIZE 100000

void *my_malloc(size_t size);

#endif /* MALLOC_H */
