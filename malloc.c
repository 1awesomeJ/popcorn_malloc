#include "malloc.h"
#include <stdio.h>

/**
 * my_malloc - allocates <size> bytes and returns a pointer
 *	to the allocated  memory.
 *
 * @size: the number of bytes to allocate
 *
 * Return: a pointer to the allocated memory.
 *	On error, NULL is returned and error is set to
 *	ENOMEM.
 *
 * Description: The memory returned is not initialized.
 *	If <size> is 0, then my_malloc() returns NULL.
 */
void *my_malloc(size_t size)
{
	void *new_mem; /* address of the new memory allocated */

	size_t alloc_size = 0; /* size to be allocated by malloc */

	static size_t total_alloc = 0; /* total memory allocated on the heap */

	static void *mem_start = NULL; /* start unused memory */

	static size_t total_bytes = 0; /* total bytes of memory used */

	if (mem_start == NULL)
		mem_start = sbrk(0);
#if DEBUG
	pre_debug(mem_start, total_bytes, total_alloc);
#endif

	if (size == 0)
		return (NULL);

	if (total_bytes + size > total_alloc)
	{
		/* get sufficient size to allocate */
		while (total_bytes + size > total_alloc + alloc_size)
			alloc_size += ALLOC_SIZE;

		/* handle failure to allocate space on if DEBUG
		 *         pre_debug(mem_start, total_bytes, total_alloc);heap */
		if (sbrk(alloc_size) == (void *)-1)
			return (NULL);

		total_alloc += alloc_size;;
	}
	/* new memory should start from unused memory */
	new_mem = mem_start;
	/* start of unused memory should be shifted forward */
	mem_start = (char *)mem_start + size;
	/* increase total used bytes */
	total_bytes += size;

#if DEBUG
	post_debug(mem_start, total_bytes, total_alloc);
#endif
	return (new_mem);
}	
