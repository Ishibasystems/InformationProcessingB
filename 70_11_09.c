#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	double a, b, c;
	
	printf("a = ");
	scanf("%lf", &a);
	printf("b = ");
	scanf("%lf", &b);
	printf("c = ");
	scanf("%lf", &c);

	printf("a >= b : %d\n", a >= b);
	printf("a > b : %d\n", a > b);
	printf("a <= b : %d\n", a <= b);
	printf("a < b : %d\n", a < b);
	printf("a == b : %d\n", a == b);
	printf("a != b : %d\n", a != b);
	printf("!(a == b) : %d\n", !(a == b));
	printf("!(a != b) : %d\n", !(a != b));
	printf("a < b && b < c : %d\n", a < b && b < c);
	printf("a < b || b < c : %d\n", a < b || b < c);

	exit(0);
}
/*
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	double a, b, c, d;
	
	printf("a = ");
	scanf("%lf", &a);
	printf("b = ");
	scanf("%lf", &b);
	printf("c = ");
	scanf("%lf", &c);
	d = b * b - 4 * a * c;

	if (d >= 0) printf("equation has real root.\n");
	else printf("equation has no real root.\n");

	exit(0);
}
*/