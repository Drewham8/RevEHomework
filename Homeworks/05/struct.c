#include <math.h>

struct Point
{
    int x;
    int y;
    int z;
};


double distance(struct Point *p1, struct Point *p2)
{
    int dx, dy, dz;
    double r;

    dx = p1->x - p2->x;
    dy = p1->y - p2->y;
    dz = p1->z - p2->z;

    r = dx*dx + dy*dy + dz*dz;

    return sqrt(r);
}


