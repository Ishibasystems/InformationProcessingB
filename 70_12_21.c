#include<stdio.h>
#include<stdlib.h>

int intmax(int, int);
int intmin(int, int);
int dumb(int, int);
int euclidean(int, int);


int main(void)
{
	int num1, num2, gcd;

	printf("Input two integers.\n");
	printf("integer 1: ");
	scanf("%d", &num1);
	printf("integer 2: ");
	scanf("%d", &num2);

	//gcd = dumb(num1, num2);
	gcd =  euclidean(num1, num2);

	printf("GCD of %d and %d is %d.\n", num1, num2, gcd);
	exit(0);
}

int intmax(int a, int b)
{
	return (a >= b ? a : b);
}

int intmin(int a, int b)
{
	return (a < b ? a : b);
}

int dumb(int a, int b)
{
	int i, m, n, common_divisor;

	m = intmax(a, b);
	n = intmin(a, b);

	if (n == 0) return m;

	for (i = 1; i <= n; i++) if (a % i == 0 && b % i == 0) common_divisor = i;

	return common_divisor;
}

int euclidean(int a, int b)
{
	int m, n, k;

	m = intmax(a, b);
	n = intmin(a, b);

	if (n == 0) return m;

	while (m % n != 0)
	{
		k = m % n;
		m = n;
		n = k;
	}

	return n;
}
