#define _USE_MATH_DEFINES

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char sx1[0x100], sx2[0x100], sy1[0x100], sy2[0x100];
	double a, b, x1, x2, y1, y2;

	printf("\nPlease input x1 ...\n?");
	fgets(sx1, 0x100, stdin);

	printf("\nPlease input y1 ...\n?");
	fgets(sy1, 0x100, stdin);

	printf("\nPlease input x2 ...\n?");
	fgets(sx2, 0x100, stdin);

	printf("\nPlease input y2 ...\n?");
	fgets(sy2, 0x100, stdin);

	x1 = atof(sx1);
	x2 = atof(sx2);
	y1 = atof(sy1);
	y2 = atof(sy2);

	if (x1 != x2){
		a = (y2 - y1) / (x2 - x1);
		b = y2 - a * x2;
		printf("\n\na = %f\nb = %f\n", a, b);
	}
	else{
		if (y1 != y2)printf("\na is not found.\nb is not found.\n", x2);
		else printf("\na is not found.\nb is not found.\n", x2);
	}

	printf("\nPlease press Enter key...\n");
	getchar();
	return;
}