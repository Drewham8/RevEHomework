#include <stdio.h>
#include <inttypes.h>

struct Complex {
    int re;
    int im;
};

void conjugate(void *p);

int main(int argc, char **argv)
{
    struct Complex c;

    c.re = 10;
    c.im = -4;

    conjugate(&c);

    printf("%i + %ii\n", c.re, c.im);
}
