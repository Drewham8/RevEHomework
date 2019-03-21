#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 104

void print_bytes(void *mem, int n)
{
    int i;
    unsigned char *ptr = mem;

    for(i=0; i<n; i++)
    {
        printf("%02x ", *ptr);
        if((i+1)%8 == 0)
        {
            printf("\n");
        }
        ptr++;
    }

    for(i=0; i<24; i++)
    {
        printf("-");
    }
    printf("\n");
}


int main(int argc, char **argv)
{
    int offset = 0;
    void *buffer;
	int i;

    buffer = calloc(BUFFER_SIZE, 1);

    print_bytes(buffer, BUFFER_SIZE);

	printf("char\n");
	for(i=0; i<10; i++)
	{
		*((char*)(buffer + offset)) = i;
		offset += sizeof(char);
	}
    print_bytes(buffer, BUFFER_SIZE);

	offset = 0;
	printf("short int\n");
	for(i=0; i<10; i++)
	{
		*((short int*)(buffer + offset)) = i;
		offset += sizeof(short int);
	}
    print_bytes(buffer, BUFFER_SIZE);

	/* repeat with int and long int types
	 */

	offset = 0;
	printf("int\n");
	for(i=0; i<10; i++)
	{
		*((int*)(buffer + offset)) = i;
		offset += sizeof(int);
	}
    print_bytes(buffer, BUFFER_SIZE);

	offset = 0;
	printf("long int\n");
	for(i=0; i<10; i++)
	{
		*((long int*)(buffer + offset)) = i;
		offset += sizeof(long int);
	}
    print_bytes(buffer, BUFFER_SIZE);

}
