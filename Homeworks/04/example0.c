#include <stdio.h>
#include <math.h>

int main(int argc, char **argv)
{
	char *str = "Hello world!";
	float fnum;
	int inum;
	double x;

	x = 4*atan(1);

	fnum = *((float*)str);
	inum = *((int*)str);

	printf("%f\n", fnum);
	printf("%i\n", inum);

	printf("%f\n", x);
	printf("%s\n", (char*)&x);

}

