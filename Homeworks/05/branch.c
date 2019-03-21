#define NORMAL 2
#define ABNORMAL 17

int junk(int x, int y, int flag)
{
    int temp;

    temp = x*y;
    if (temp % 2)
    {
        if (NORMAL == flag)
        {
            return 0;
        }
        else if (ABNORMAL == flag)
        {
            return 17;
        }
    }

    temp = temp - x;

    return temp;
}
