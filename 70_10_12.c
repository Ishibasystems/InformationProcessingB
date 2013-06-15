#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int a = 10, b, c, d, e, f;
	b = a + 5;
	c = a + b;
	d = a - b;
	e = a * b;
	f = a / b;
	printf("a = %d\n", a);
	printf("b = %d\n", b);
	printf("c = %d\n", c);
	printf("d = %d\n", d);
	printf("e = %d\n", e);
	printf("f = %d\n", f);
	exit(0);
}