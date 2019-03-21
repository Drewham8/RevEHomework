#include <stdio.h>

int main()
{
    float fl=3.14;
    unsigned long int addr=(unsigned long int)&fl;

    printf("sizes:\n");
    printf("  float: %lu\n", sizeof(float));
    printf("  int: %lu\n", sizeof(unsigned int));
    printf("  long int: %lu\n", sizeof(unsigned long int));

    printf("\n");

    printf("values:\n");
    printf("  %.2f\n", fl);
    printf("  %.2f\n", *(float*)addr);
    printf("  %x\n", *(unsigned int*)addr);
    printf("  %lx\n", *(unsigned long int*)addr);
    printf("  %i\n", *(unsigned char*)addr);

    printf("\n");

    printf("addresses:\n");
    printf("  %p\n", &fl);
    printf("  0x%lx\n", addr);
    return 0;
}

