#include "malloc.h"
#include <stdio.h>

void pre_debug(void *mem_start, size_t total_bytes, size_t total_alloc)
{
	printf("\nBEFORE ALLOCATION\n=================\n");
        printf("program's break -> %p\n", sbrk(0));
        printf("start of unused memory -> %p\n", mem_start);
        printf("total bytes used -> %lu bytes\n", total_bytes);
        printf("total bytes allocated -> %lu bytes\n", total_alloc);
}

void post_debug(void *mem_start, size_t total_bytes, size_t total_alloc)
{
	printf("\nAFTER ALLOCATION\n================\n");
        printf("program's break -> %p\n", sbrk(0));
        printf("start of unused memory -> %p\n", mem_start);
        printf("total bytes used -> %lu bytes\n", total_bytes);
        printf("total bytes allocated -> %lu bytes\n", total_alloc);	
}

