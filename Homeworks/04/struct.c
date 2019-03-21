#include <stdio.h>
#include <string.h>
#include <stdlib.h>





int main(int argc, char **argv)
{
  struct my_struct s;

    s.w=5;
    s.x=1;
    s.y=2;
    s.z=3;

    print_bytes(&s, sizeof(s));


}
