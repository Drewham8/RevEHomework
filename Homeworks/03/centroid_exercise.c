#include <stdlib.h>
#include <stdio.h>

struct Point {
    double x;
    double y;
};

/* This function's job is to compute the centroid of a set of points.
 * The centroid's x coordinate is the average of the x coordinates of
 * the set, and the centroid's y coordinate is the average of the y
 * coordinates of the set.
 */
struct Point centroid(struct Point *v, int len)
{
    struct Point c;
    int i;

    c.x = 0.0;
    c.y = 0.0;

    for(i=0; i<len; i++)
    {
        c.x += v[i].x;
        c.y += v[i].y;
    }

    c.x /= len;
    c.y /= len;

    return c;
}

/* You won't know how many points you have to read ahead of time.
 * You'll need to adjust the size of my_array as you go.
 */
int main(int argc, char **argv)
{
    struct Point *my_array;
    struct Point c;
    double x, y;
    int ctr = 0;
    int array_size = 10;

    my_array = malloc(array_size * sizeof(struct Point));

    /* this will loop until encountering EOF if reading from a file or
     * else ^D if reading from the keyboard
     */
    while( EOF!=scanf("%lf%lf", &x, &y) )
    {
        my_array[ctr].x = x;
        my_array[ctr].y = y;
        printf("read (%f, %f)\n", x, y);
        ctr++;
        if (ctr >= array_size)
        {
            struct Point *tmp;

            tmp = realloc(my_array, 2*array_size*sizeof(struct Point));
            if (tmp)
            {
                my_array = tmp;
                array_size *= 2;
                printf("doubling\n");
            }
            else
            {
                printf("panic!!!!!!1!\n");
                exit(1);
            }
        }
    }

    c = centroid(my_array, ctr);
    printf("the centroid is %f %f\n", c.x, c.y);

    free(my_array);
}
