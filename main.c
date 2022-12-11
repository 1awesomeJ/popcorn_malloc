#include "malloc.h"
#include <stdio.h>

int main(void)
{
	char *my_string;
	int *my_int;
	double *my_double;
	char *my_char;
	void *my_large;
	int i;

	printf("\n------------------------ MY STRING[%lu bytes] ------------------------\n", sizeof(char) * 27);
	my_string = my_malloc(27);
	printf("\n------------------------ MY INT[%lu bytes] ---------------------------\n", sizeof(int));
	my_int = my_malloc(sizeof(int));
	printf("\n------------------------ MY DOUBLE[%lu bytes] ------------------------\n", sizeof(double));
	my_double = my_malloc(sizeof(double));
	printf("\n------------------------ MY CHAR[%lu bytes] --------------------------\n", sizeof(char));
	my_char = my_malloc(sizeof(char));
	printf("\n------------------------ MY LARGE[%lu bytes] --------------------------\n", (size_t)ALLOC_SIZE);
	my_large = my_malloc(ALLOC_SIZE);
	printf("\n----------------------------------------------------------------------\n");

	/* check if malloc failed at any point */
	if (!(my_string && my_int && my_double && my_char))
	{
		/* TODO: free all memory */
		return (1);
	}

	/* my_string should contain all uppercase letters */
	for (i = 0; i < 26; i++)
		my_string[i] = 'A' + i;
	my_string[i] = '\0';

	*my_int = 102404201;
	*my_double = 12345.67890;
	*my_char = '$';
	(void)my_large;

	printf("my_string -> %s\n", my_string);
	printf("my_int -> %d\n", *my_int);
	printf("my_double -> %f\n", *my_double);
	printf("my_char -> %c\n", *my_char);

	/* TODO: free all memory */

	return (0);
}
