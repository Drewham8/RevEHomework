#include <stdio.h>

int main(int argc, char **argv)
{
	int i;
	int v[10];
	int *p;


	for(i=0; i<10; i++)
	{
		v[i] = i;
	}

	p = v;

	/* output the array using pointers
	 */
	for(i=0; i<10; i++)
	{
		printf("addr: %p\n", p);
		printf("   %i\n", *p);

		p = (int*)((unsigned char*)p + sizeof(int));
	}

}
