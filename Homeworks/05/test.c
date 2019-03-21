#include <stdio.h>

int factorial(int n)
{
    int product = 1;

    while(n>1)
    {
        product *= n;
        n--;
    }
}
        

int main(int argc, char **argv)
{
    printf("5! is %i\n", factorial(5));
}
