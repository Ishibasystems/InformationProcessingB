#include<stdio.h>

int main(void)
{
	//double x[3], y[3], inner_product = 0;
	//int i;
	//for(i = 0; i < 3; i++){printf("Input x[%d]: ", i); scanf("%lf", &x[i]);}
	//for(i = 0; i < 3; i++){printf("Input y[%d]: ", i); scanf("%lf", &y[i]);}
	//for(i = 0; i < 3; i++){inner_product += x[i] * y[i];}
	//printf("inner product is %f.\n", inner_product);
	int father_blood, mother_blood, blood[4][4] = {{1, 2, 3, 1}, {2, 4, 3, 4}, {3, 3, 3, 5}, {1, 4, 5, 6}};
	
	printf("Input blood type of your father (A=1, B=2, AB=3, O=4) : ");
	scanf("%d", &father_blood);
	printf("Input blood type of your mother (A=1, B=2, AB=3, O=4) : ");
	scanf("%d", &mother_blood);

	printf("You may have blood type ");
	switch (blood[father_blood - 1][mother_blood - 1])
	{
	case 1:
		printf("A or O");
		break;
	case 2:
		printf("A, B, AB or O");
		break;
	case 3:
		printf("A, B or AB");
		break;
	case 4:
		printf("B or O");
		break;
	case 5:
		printf("A or B");
		break;
	case 6:
		printf("O");
		break;

	}
	printf(".\n");
	exit(0);
}

