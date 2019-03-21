#include <stdio.h>

// we need stdlib.h to get a function declaration of random and srandom
#include <stdlib.h>

// we need time.h to get a function declaration of time
#include <time.h>

int main(int argc, char **argv)
{
    long int sample;
    int x=10, y=7;
    int i;

    for(i=0; i<x; i++)
    {
        printf("%i ", i);
    }
    printf("\n");

    i=y;
    while(i > 0)
    {
        printf("%i ", i);
        i--;
    }
    printf("\n");

    srandom(time(NULL));
    sample = random();
    if (sample % 2)
    {
        printf("%li is odd\n", sample);
    }
    else
    {
        printf("%li is even\n", sample);
    }

    // this block is only for the purpose of local scoping of ratio
    {
        double ratio = x / y;
        printf("%f\n", ratio);

        ratio = (double)x / y;
        printf("%f\n", ratio);
    }

    return 0;
}

