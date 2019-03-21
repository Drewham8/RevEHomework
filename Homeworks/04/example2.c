#include <stdio.h>

void float_func(unsigned long int fptr)
{
    *(float*)fptr=99.9;
}

/* define a function that updates a region of memory as though that region
 * contains a value of type unsigned int
 */ 
void int_func(unsigned long int iptr)
{

    *(unsigned int*)iptr=42;
}

int main()
{
    float fl=3.14;
    unsigned long int addr=(unsigned long int)&fl;

    float_func(addr);
    printf("%.2f\n", fl);

    int_func(addr);

    printf("%.2f\n", fl);

    printf("%u\n", *(unsigned int*)addr);
    /* verify that you correctly updated memory */

    return 0;
}

