#define _USE_MATH_DEFINES

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
	char sR1[0x100], sR2[0x100];
	double R1, R2;

	printf("\nPlease input first circle's radius R1 ...\n?");
	fgets(sR1, 0x100, stdin);

	printf("\nPlease input second circle's radius R2 ...\n?");
	fgets(sR2, 0x100, stdin);

	R1 = atof(sR1);
	R2 = atof(sR2);

	//printf("\nArea of first circle \n%f * %f * ƒÎ = %f\n", R1, R1, R1 * R1 * M_PI);
	//printf("\nArea of second circle \n%f * %f * ƒÎ = %f\n", R2, R2, R2 * R2 * M_PI);
	printf("\nArea of two circle is\n%f\n", (R1 * R1 + R2 * R2) * M_PI);

	printf("\nPlease press Enter key\n");
	getchar();
	return;
}