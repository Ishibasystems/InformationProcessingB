/* ��񏈗�B report2ex.c */
/* �ۑ�Ԃ��σX�^�C�� (BSD/Allman Style) */
/* VisualStudio2012 GCC4.2.1 Clang3.1 �œ���m�F */
/* 2013.06.16, 10RU004, �΋��ˑ� */

#include <stdio.h>	/*�W�����o�͊֐� */
#include <stdlib.h>	/*�W�����C�u���� */
#include <string.h>	/*�����񃉃C�u���� */
#include <time.h>	/*�����n���C�u���� */

/* �萔�錾 */
#define XMAX 5	/* �t�B�[���h��X�傫�� */
#define YMAX 5	/* �t�B�[���h��Y�傫�� */
#define GMIN 43	/* ������������ */
#define GMAX 47	/* ����������� */

/* �֐��錾 */
void input(char *, long);

int main(int argc, char *argv[])
{
	char movex = 0, movey = 0, ex[2], ey[2], field[XMAX * YMAX] = {0}, i, j, getm, direc[2] = {0}, scanp[2] = {0};
	short gold = 0;
	/*	movex	X���W	�����̂���X���W */
	/*	movey	Y���W	�����̂���Y���W */
	/*	ex[]	X���W	�����̂���X���W */
	/*	ey[]	Y���W	�����̂���Y���W */
	/*	field[]	�t�B�[���h��ԃt���O�������Ă���z��ϐ� */
	/*	i	�J�E���^	�J�E���g������ϐ� */
	/*	j	�J�E���^	�J�E���g������ϐ� */
	/*	getm	����	�E�����z������ϐ� */
	/*	direc[]	����	�ړ������̓��͂�����ϐ� */
	/*	scanp[]	����	�T�����邩�̗L���̓��͂�����ϐ� */
	/*	gold	����	�����̎����Ă�����z */

	srand(time(NULL));	/* �����n��̕ύX(rand�֐��̏�����) */

	/* �����̏ꏊ�����߂�(ex,ey�̏�����)���̕��@�ňꌂ�ɂăX�^�[�g�n�_(0,0)�ȊO�ŉ����������}�X�ɂȂ�Ȃ��悤�Ɍ��肷�� */
	ex[0] = rand() % XMAX;	/* ����0��X���W��I��(0-4�̗�������) */
	ey[0] = rand() % (YMAX - (ex[0] == 0)) + (ex[0] == 0);	/* ����0��Y���W��I��(0-4�̗��������A����0��X���W��0�Ȃ�1-4�̗�������) */
	ex[1] = rand() % XMAX;	/* ����1��X���W��I��(0-4�̗�������) */
	ey[1] += ey[0] <= (ey[1] = rand() % (YMAX - (ex[1] == ex[0]) - (ex[1] == 0)) + (ex[1] == 0)) && ex[1] == ex[0];
	/* ����1��Y���W��I��(����1��X���W��ɃX�^�[�g�n�_�E����0������ƑI�ׂ�Y���W�����ǂ�ǂ񌸂�) */

	for(;;)	/* �Q�[���J�n(�������[�v) */
	{
		/* �t�B�[���h��\������ */
		for (i = 0; i < YMAX; printf("\n") && i++)	/* �t�B�[���h�̏�Ԃ�\�����Ă��� */
			for (j = 0; j < XMAX; j++ == movex && i == movey ? printf(" 1") : printf("%2d", field[j + i * XMAX - 1]));

		/* �ړ���������͂�����(direc) */
		printf("\nInput, where you going? (Up:1, Down:2, Left:3, Right:4): ");
		input(direc, 2);

		/* ���͂��ꂽ�ړ��������ʂɏ]���Ď����̍��W��ύX(�ړ�)���� */
		movey -= direc[0] == '1';	/* ��Ɉړ�(Y���W�����炷) */
		movey += direc[0] == '2';	/* ���Ɉړ�(Y���W�𑝂₷) */
		movex -= direc[0] == '3';	/* ���Ɉړ�(X���W�����炷) */
		movex += direc[0] == '4';	/* �E�Ɉړ�(X���W�𑝂₷) */

		/* �t�B�[���h�O�ɏo�Ă��܂����ꍇ�͍��W���C������ */
		if (movex < 0) movex = 0;	/* ���Ɉړ��������� */
		if (movey < 0) movey = 0;	/* ��Ɉړ��������� */
		if (movex >= XMAX) movex = XMAX - 1;	/* �E�Ɉړ��������� */
		if (movey >= YMAX) movey = YMAX - 1;	/* ���Ɉړ��������� */

		/* �t�B�[���h�̃}�X�ڂ̒T�� */
		if ((movex != 0 || movey != 0) && field[movex + movey * XMAX] == 0)	/* �X�^�[�g�n�_(0,0)�ȊO�Ȃ璲���\ ���T���̃}�X�ڂ̂ݑI�������o�� */
		{
			/* �����̗L������͂�����(scanp) */
			printf("Input, Check or Through? (Check:1, Through:Other):");
			input(scanp, 2);

			if (scanp[0] == '1')	/* �������� */
			{
				if ((movex == ex[0] && movey == ey[0]) || (movex == ex[1] && movey == ey[1]))	/* �����̍��W������0 or ����1�̍��W�Ɠ����������Ƒ��� */
				{	/* �����ɑ��� */
					gold = gold / 2 + gold % 2;	/* gold�𔼕������A�؂�グ */
					printf("Monster: Gold has become a half.\n\n");
					field[movex + movey * XMAX] = -1;	/* �}�X�ڂ̏�Ԃ������ɂ��� */
				}
				else
				{	/* �������� */
					printf("You get %d gold.\n\n", getm = rand() % 8 + 2);	/* ������gold��I��(2-9�̗�������)�A�\�� */
					gold += field[movex + movey * XMAX] = getm;	/* �}�X�ڂ̏�Ԃ𓾂�ꂽgold�ɂ��Agold�ɓ���ꂽgold��ǉ����� */
				}
			}
		}

		/* �S�[���ɒ��������� */
		if (movex == (XMAX - 1) && movey == (YMAX - 1))
		{
			printf("You have %d gold.\n", gold);
			/* �▭�ȏ�������(���T�������������̂�) */
			if (GMIN <= gold && gold <= GMAX)
			     printf("You wins!\n");	/* ���Ȃ��̏����ł� */
			else printf("You lost!!\n");	/* ���Ȃ��̕����ł� */
			break;	/* �Q�[����for��(�������[�v)���甲���� */
		}
	}
	printf("\n> Thank you for playing! <\n");	/* �֑� */
	return 0;	/* �I�� */
}

void input(char s[], long len)	/* ���͊֐� */
{
	fgets(s, len, stdin);

	if (strchr(s, '\n') != 0) s[strlen(s) - 1] = '\0';
	else while (getchar() != '\n');

	return;
}