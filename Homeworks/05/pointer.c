void manipulate(int *p, int new)
{
    int x;
    int *y;

    y = &x;
    *y = new;
    *p = new;
}
