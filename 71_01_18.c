#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double distance(double, double, double, double);

int main(void)
{
	double x[2], y[2], d;
	int i;
	
	printf("Input coordinates of two points on Euclidean plane:\n");
	for(i = 0; i < 2; i++)
	{
		printf("x%d: ", i + 1);
		scanf("%lf", &x[i]);
		printf("y%d: ", i + 1);
		scanf("%lf", &y[i]);
	}

	printf("Distance of two points is %f.\n",
		distance(x[0], y[0], x[1], y[1]));
	exit(0);
}

double distance(double x1, double y1, double x2, double y2)
{
	double dx = x1 - x2, dy = y1 - y2;
	return sqrt(dx * dx + dy * dy);
}