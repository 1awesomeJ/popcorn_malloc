#include<stdio.h>
#include <unistd.h>


void *ptr_ret =NULL;
int total = 0;
void* _malloc(int size)
{
void *ptr_malloc, *old_pb, *new_pb;
	if ((ptr_ret == NULL) || (total >= 100000))
	{
	old_pb = sbrk(0);	
	new_pb = sbrk(100000);	
	new_pb = sbrk(0);
	ptr_ret = old_pb;
	printf("Yes!!\n");
	}
	printf("old pb %p\n", old_pb);
	printf("new pb %p\n", new_pb);
	ptr_malloc = ptr_ret;
	ptr_ret += size;
	total += size;
	printf("malloc return %p\n", ptr_malloc);
	printf("total allocated: %d\n", total);

}
int main()
{
_malloc(200);
_malloc(500);
_malloc(1000);
_malloc(2000);
}
