#ifndef MALLOC_H
#define MALLOC_H
#include <unistd.h>
#include <stddef.h>

/* size we'll allocated using sbrk */
#define ALLOC_SIZE 10000

/* debugging mode toggle */
#define DEBUG 1

void *my_malloc(size_t size);

void pre_debug(void *mem_start, size_t total_bytes, size_t total_alloc);
void post_debug(void *mem_start, size_t total_bytes, size_t total_alloc);

#endif /* MALLOC_H */
