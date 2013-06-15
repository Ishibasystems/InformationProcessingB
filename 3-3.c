//この課題は 加点課題 です。

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
	char buf[256];
	//	buf	入力の文字列(一行取り込み用)

	int cot[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0}, d, p = 1000, q = 0, r, cnt, s, rcnt, hit, blow;
	//	cot		数字重複防止のフラグ
	//	d		乱数入れ(1～9)
	//	p		乱数生成時の位摂り
	//	q		生成乱数(4桁)
	//	r		4桁比較時の生成乱数の1/値
	//	cnt		現在の試行数カウンタ
	//	s		4桁比較時の入力数値の1/値
	//	rcnt	4桁比較時のカウンタ
	//	hit		4桁比較時のHit数
	//	blow	4桁比較時のBlow数

	srand(time(NULL));

	for(;;)
	{
		d = rand() % 9 + 1;
		if (cot[d - 1] == 0)
		{
			cot[d - 1] = 1;
			q += d * p;
			p /= 10;
			if (p == 0) break;
		}
	}

	for(cnt = 0; cnt < 10; cnt++)
	{
		printf("Take%d\nMake a guess the number : ", cnt + 1);
		gets(buf);
		if (sscanf(buf, "%4d", &s) != 1) break;

		hit = 0;
		blow = 0;
		r = q;

		for(rcnt = 0; rcnt < 4; rcnt++)
		{
			if (cot[s % 10 - 1] == 1) blow++;
			if (s % 10 == r % 10) hit++;
			s /= 10;
			r /= 10;
		}
		if (hit == 4) break;
		printf("%d Hit%d Blow\n\n", hit, blow - hit);
	}

	if (hit == 4) printf("GAME CLEAR!");
	else printf("GAME OVER");

	printf("\n\nThank you for playing!\n");
	exit(0);
}
