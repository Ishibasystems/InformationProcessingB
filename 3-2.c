//���̉ۑ�� ���_�ۑ� �ł��B

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void printint(const unsigned int);
//	unsigned int��\������֐�

int main(void)
{
	char buf[256];
	//	buf	���͂̕�����(��s��荞�ݗp)

	unsigned int s = UINT_MAX;
	//	s	�\������ϐ�(��ԍŏ���unsigned int�̍ő�l����)

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
	//	i	������(�t�]�i�[)
	//	buf	������(�����i�[)

	int cnt, cnt2;
	//	cnt 	������J�E���^
	//	cnt2	�t�]�p�J�E���^

	unsigned int b = a;
	//	b	�����̃R�s�[

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