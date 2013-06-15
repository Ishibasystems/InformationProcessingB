#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	double x, y;
	int i = 10, j = 20;

	x = i / j * 30.0;
	y = i * 30.0 / j;

	printf("x = %f, y = %f\n", x, y);
	exit(0);
}