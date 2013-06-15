#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i;

	printf("Input Intenger: ");
	scanf("%d", &i);

	printf("%d * %d = %d\n", i, i, i * i);
	exit(0);
}