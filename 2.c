#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
	int sn, gn, pt, apt = 0;
	//	sn	答えの数字
	//	gn	入力の数字
	//	pt	現ゲームの点数(11-回数)
	//	apt	総合点数

	char buf[256];
	//	buf	入力の文字列(一行取り込み用)

	srand(time(NULL));

	printf("game start.\n\n");
	for(;;)
	{
		sn = rand() % 900 + 100;

		for(pt = 10; pt > 1; pt--)
		{
			printf("Make a guess the number : ");
			gets(buf);
			
			if (sscanf(buf, "%d", &gn) != 1 || gn < 100 || 999 < gn)
			{
				printf("Input number is failed.\n\n");
				pt++;
				continue;
			}

			printf("Take%d : ", 11-pt);

			if (gn == sn){ printf("Bingo!\nYou get %d points.\n\n", pt); break;}

			printf("You missed.\tHints : You number is ");

			if (sn < gn) printf("larger");
			else printf("smaller");

			printf(".\n\n");
		}

		if (pt > 1) apt += pt;
		else
		{
			printf("You're charenge failed.\nAnswer is %d\nYou lose 2 points.\n\n", sn);
			apt -= 2;
		}

		printf("Total : %d pt\n", apt);

		if (apt <= 0){printf("GAME OVER"); break;}
		if (apt >= 50){printf("GAME CLEAR!"); break;}

		printf("Continue? Yes = 1, No = Otherwise : ", apt);
		gets(buf);

		if (sscanf(buf, "%d", &gn) != 1 || gn != 1){printf("GAME OVER"); break;}

		printf("new game start.\n\n");
	}
	printf("\n\nThanks you for playing!\n");

	exit(0);
}