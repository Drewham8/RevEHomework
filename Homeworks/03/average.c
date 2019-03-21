#include <stdlib.h>
#include <stdio.h>

double average(int *v, int len)
{
    int i;
    double sum = 0.0;

    for(i=0; i<len; i++)
    {
       sum += v[i];
    }

    return sum/len;
}

int main(int argc, char **argv)
{
    int *my_array;
    int size, ctr, x;

    scanf("%i", &size);

    my_array = calloc(size, sizeof(int));

    for (ctr=0; ctr<size; ctr++)
    {
        scanf("%i", &x);
        my_array[ctr] = x;
    }

    printf("the average value is %f\n", average(my_array, size));

    free(my_array);

}
