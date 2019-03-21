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

struct my_struct {
    double x;
    unsigned int y;
    unsigned int z;
};

int main(int argc, char **argv)
{
    int free_offset = 0;
    void *buffer;
    double *pi;
    unsigned int *cow;
    unsigned int *cafeteria;

    struct my_struct *my_ptr;

    buffer = calloc(BUFFER_SIZE, 1);

    print_bytes(buffer, BUFFER_SIZE);

    pi = buffer;
    *pi = 3.1415;
    free_offset += sizeof(*pi);

    print_bytes(buffer, BUFFER_SIZE);

    cow = buffer + free_offset;
    *cow = 0xdeadbeef;
    free_offset += sizeof(*cow);

    print_bytes(buffer, BUFFER_SIZE);

    cafeteria = buffer + free_offset;
    *cafeteria = 0xbadf00d;
    free_offset += sizeof(*cafeteria);

    print_bytes(buffer, BUFFER_SIZE);

	printf("%f\n", *pi);
    printf("%x\n", *cow);
    printf("%x\n", *cafeteria);


	/* appropriately set my_ptr to access what we've written to memory as a
	 * struct
	 */

    my_ptr = buffer;

    printf("%f\n", my_ptr->x);
    printf("0x%08x\n", my_ptr->y);
    printf("0x%08x\n", my_ptr->z);
}
