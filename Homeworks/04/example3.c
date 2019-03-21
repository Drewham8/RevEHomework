#include <stdio.h>


int main()
{
    char *str = "The quick brown fox jumps over the lazy dog.";
	double x;

    unsigned long int addr= (unsigned long int)str;

	x = *(double*)str;

    printf("%s\n", (char*)addr);
    printf("%s\n", (char*)(addr+4));
    printf("%s\n", (char*)(addr+20));

	printf("%f\n", x);

    return 0;
}

