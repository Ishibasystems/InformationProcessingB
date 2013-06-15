//この課題は 加点課題 です。

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void printint(const unsigned int);
//	unsigned intを表示する関数

int main(void)
{
	char buf[256];
	//	buf	入力の文字列(一行取り込み用)

	unsigned int s = UINT_MAX;
	//	s	表示する変数(一番最初はunsigned intの最大値を代入)

	puts("Maximal value which can be stored in an unsigned int variable is : ");
	printint(s);
	puts("\n\n");

	puts("Make a guess the number : ");

	gets(buf);
	if (sscanf(buf, "%I64u", &s) == 1) printint(s);

	exit(0);
}

void printint(const unsigned int a)
{
	char i[20], buf[20];
	//	i	文字列(逆転格納)
	//	buf	文字列(正順格納)

	int cnt, cnt2;
	//	cnt 	文字列カウンタ
	//	cnt2	逆転用カウンタ

	unsigned int b = a;
	//	b	引数のコピー

	for(cnt = 0; cnt < 20; cnt++)
	{
		buf[cnt] = b % 10 + '0';
		b /= 10;
		if (b == 0) break;
	}

	buf[cnt + 1] = '\0';
	i[cnt + 1] = '\0';

	for(cnt2 = 0; cnt >= 0; cnt--) i[cnt2++] = buf[cnt];
	
	puts(i);

	return;
}