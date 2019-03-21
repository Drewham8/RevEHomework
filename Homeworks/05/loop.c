int loopy(int x)
{
    int i, ctr, sum=0;

    for(i=0; i<x; i++)
    {
        sum += i;
    }

    ctr = 0;
    while (ctr < x)
    {
        sum += ctr;
        ctr++;
    }

    return sum;
}
