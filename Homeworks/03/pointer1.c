#include <stdio.h>

int main(int argc, char **argv)
{
    int y=10;
    int *x;

    *x = 10;
    
    printf("y at %p\n", &y);
    printf("x at %p\n", &x);

    printf("\nx initially points to %p\n", x);

    x = &y;

    printf("now x points to %p\n\n", x);
    printf("the int pointed to by x has value %i\n", *x);

    *x = 42;

    printf("y's value been changed via x %i\n", y);
}
