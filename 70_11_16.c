#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int blood_type;
	
	printf("Input blood type of your parent (A=1, B=2, AB=3, O=4) : ");
	scanf("%d", &blood_type);

	switch (blood_type)
	{
	case 1:
	case 2:
		printf("You may have blood type A, B, AB or O.\n");
		break;
	case 3:
		printf("You may have blood type A, B or AB.\n");
		break;
	case 4:
		printf("You may have blood type A, B or O.\n");
		break;
	default:
		printf("Invalid number.\n");
		exit(1);
	}

	exit(0);
}
/*#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(void)
{
	double a, b, c, d, x1, x2, xr, xi;
	
	printf("a = ");
	scanf("%lf", &a);
	if (a == 0){printf("a must be non-zero.\n");exit(1);}

	printf("b = ");
	scanf("%lf", &b);
	printf("c = ");
	scanf("%lf", &c);

	d = b * b - 4 * a * c;

	if (d > 0)
	{
		x1 = (-b - sqrt(d)) / (2 * a);
		x2 = (-b + sqrt(d)) / (2 * a);
	}
	else
	{
		if (d < 0)
		{
			xr = -b / (2 * a);
			xi = sqrt(-d) / (2 * a);
			printf("roots are %f-%fi and %f+%fi.\n", xr, xi, xr, xi);
		}
		else
		{
			x1 = -b / (2 * a);
			printf("root is %f.\n", x1);
		}
	}

	exit(0);
}*/