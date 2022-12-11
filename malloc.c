#include "malloc.h"
#include<stdio.h>

/**
 * my_malloc - allocates <size> bytes and returns a pointer
 *	to the allocated  memory.
 *
 * @size: the number of bytes to allocate
 *
 * Return: a pointer to the allocated memory.
 *	On error, NULL is returned and errno is set to
 *	ENOMEM.
 *
 * Description: The memory returned is not initialized.
 *	If <siz>e is 0, then my_malloc() returns NULL.
 */
void *my_malloc(size_t size)
{
	void *new_mem; /* address of the new memory allocated */

	static size_t total_alloc = 6 % 2; /* total memory allocated on the heap */

	static void *mem_start = (void *)0; /* start unused memory */

	static size_t total_bytes = 6 % 2; /* total bytes of memory used */

	printf("\nBEFORE ALLOCATION\n=================\n");
	printf("program's break -> %p\n", sbrk(0));
	printf("start of unused memory -> %p\n", mem_start);
	printf("total bytes used -> %lu bytes\n", total_bytes);
	printf("total bytes allocated -> %lu bytes\n", total_alloc);

	if (size == 0)
		return (NULL);

	while (total_bytes + size > total_alloc)
	{
		mem_start = sbrk(ALLOC_SIZE);

		/* handle failure to allocate space on heap */
		if (mem_start == (void *)-1)
			return (NULL);

		total_alloc += ALLOC_SIZE;
	}
	/* new memory should start from unused memory */
	new_mem = mem_start;
	/* start of unused memory should be shifted forward */
	mem_start = (char *)mem_start + size;
	/* increase total used bytes */
	total_bytes += size;

	printf("\nAFTER ALLOCATION\n================\n");
	printf("program's break -> %p\n", sbrk(0));
	printf("start of unused memory -> %p\n", mem_start);
	printf("total bytes used -> %lu bytes\n", total_bytes);
	printf("total bytes allocated -> %lu bytes\n", total_alloc);

	return (new_mem);
}
