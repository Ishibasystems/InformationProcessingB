/*#include<stdio.h>

int main(void)
{
	int a, b;

	for(a = 1; a < 10; a++)
	{
		for(b = 1; b < 10; b++)
		{
			if (a * b > 30) break;
			printf("%d * %d = %d\n", a, b, a * b);
		}
	}
	exit(0);
}
*/
/*
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
	int sn, gn;

	srand(time(NULL));

	sn = rand() % 9 + 1;
	while (1)
	{
		printf("Make a guess the number: ");
		scanf("%d", &gn);
		if (gn != sn)
		{
			printf("You missed.\n");

			printf("Hints: You number is ");
			if (sn < gn) printf("larger");
			else printf("smaller");
			printf(".\n\n");

		}
		else
		{
			printf("Bingo!\n");
			break;
		}
	}

	exit(0);
}
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
	int sn, gn, pt, apt = 0;
	char buf[256];

	srand(time(NULL));

	printf("game start.\n\n");
	for(;;)
	{
		sn = rand() % 900 + 100;

		for(pt = 10; pt > 1; pt--)
		{
			printf("Make a guess the number: ");
			gets(buf);
			
			if (sscanf(buf, "%d", &gn) != 1 || gn < 100 || 999 < gn){ printf("Input number is failed.\n\n"); pt++; continue;}

			if (gn == sn){ printf("Bingo!\nYou get %d points.\n\n", pt); break;}

			printf("You missed.\tHints: You number is ");

			if (sn < gn) printf("larger");
			else printf("smaller");

			printf(".\n\n");

		}

		if (pt > 1) apt += pt;
		else printf("You're charenge failed.\nAnswer is %d\n\n", sn);

		printf("Total : %d pt\nContinue? Yes = 1, No = Otherwise : ", apt);
		gets(buf);

		if (sscanf(buf, "%d", &gn) != 1 || gn != 1) break;

		printf("new game start.\n\n");

	}
	printf("GAME OVER\n\nThanks you for playing!\n");

	exit(0);
}