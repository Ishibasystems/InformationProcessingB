//���̉ۑ�� ���_�ۑ� �ł��B

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
	char buf[256];
	//	buf	���͂̕�����(��s��荞�ݗp)

	int cot[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0}, d, p = 1000, q = 0, r, cnt, s, rcnt, hit, blow;
	//	cot		�����d���h�~�̃t���O
	//	d		��������(1�`9)
	//	p		�����������̈ʐۂ�
	//	q		��������(4��)
	//	r		4����r���̐���������1/�l
	//	cnt		���݂̎��s���J�E���^
	//	s		4����r���̓��͐��l��1/�l
	//	rcnt	4����r���̃J�E���^
	//	hit		4����r����Hit��
	//	blow	4����r����Blow��

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
