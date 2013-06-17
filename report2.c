/* ��񏈗�B report2.c */
/* K&R�X�^�C�����������Ă���� */
/* 2013.06.16, TDUCC, ���㐰�� */

#include <stdio.h>	/*�W�����o�͊֐� */
#include <stdlib.h>	/*�W�����C�u���� */
#include <time.h>	/*�������C�u���� */

/* main�֐� */
int main(void)
{
	int movex, movey, gold, ex[2], ey[2], field[5][5], i, j, getm, direction, scanp;
	/*	movex	X���W	�����̂���X���W */
	/*	movey	Y���W	�����̂���Y���W */
	/*	gold	����	�����̎����Ă�����z */
	/*	ex[]	X���W	�����̂���X���W */
	/*	ey[]	Y���W	�����̂���Y���W */
	/*	field[][]	�t�B�[���h�}�X�ڂ̏�ԃt���O�������Ă���z��ϐ� */
	/*	i	�J�E���^	while���ł̃J�E���g������ϐ� */
	/*	j	�J�E���^	while���ł̃J�E���g������ϐ� */
	/*	getm	����	�E�����z������ϐ� */
	/*	direction����	�ړ������̓��͂�����ϐ� */
	/*	scanp	����	�T�����邩�̗L���̓��͂�����ϐ� */

	/* �����n��̕ύX(rand�֐��̏�����) */
	srand(time(NULL));

	/* �t�B�[���h��0�Ŗ��߂�(field������) */
	i = 0;
	while (i < 5) {
		j = 0;
		while (j < 5) {
			field[i][j] = 0;	/* �t�B�[���h��0�ɐݒ� */
			j++;
		}
		i++;
	}

	/* �����̏ꏊ��ݒ肷��(movex,movey�̏�����) */
	movex = 0;	/* ������X���W(�X�^�[�g�n�_) */
	movey = 0;	/* ������Y���W(�X�^�[�g�n�_) */

	/* �����̎����Ă�����z��ݒ肷��(gold�̏�����) */
	gold = 0;	/* �����̎����Ă�����z(�J�n���_) */

	/* ����0�̏ꏊ�����߂�(ex[0],ey[0]�̏�����) */
	do {
		ex[0] = rand() % 5;	/* ����0��X���W��I��(0-4�̗�������) */
		ey[0] = rand() % 5;	/* ����0��Y���W��I��(0-4�̗�������) */
	} while (ex[0] == 0 && ey[0] == 0);	/* �X�^�[�g�n�_(0,0)�Ȃ�I�тȂ��� */

	/* ����1�̏ꏊ�����߂�(ex[1],ey[1]�̏�����) */
	do {
		ex[1] = rand() % 5;	/* ����1��X���W��I��(0-4�̗�������) */
		ey[1] = rand() % 5;	/* ����1��Y���W��I��(0-4�̗�������) */
	} while ((ex[1] == 0 && ey[1] == 0) || (ex[1] == ex[0] && ey[1] == ey[0]));
	/* �X�^�[�g�n�_(0,0)�������͉���0�̏ꏊ(ex[0],ey[0])�Ȃ�I�тȂ��� */

	/* �Q�[���J�n(�������[�v) */
	while (1){
		/* �t�B�[���h��\������ */
		i = 0;
		while (i < 5) {
			j = 0;
			while (j < 5) {
				if (i == movey && j == movex) {	/* �����̂�����W�Ȃ� */
					printf(" 1");	/* ����(1)��\������ */
				} else {	/* ���������Ȃ����W�Ȃ� */
					printf("%2d", field[j][i]);	/* �t�B�[���h�̏�Ԃ�\�����Ă��� */
				}
				j++;
			}
			printf("\n");	/* ���s(���̍s) */
			i++;
		}
		printf("\n");	/* report02-tue4.pdf�̕\����ʂ�ɂ��邽�� */

		/* �ړ���������͂�����(direction) */
		printf("Input, where you going? (Up:1, Down:2, Left:3, Right:4): ");
		scanf("%d", &direction);

		/* ���͂��ꂽ�ړ��������ʂɏ]���Ď����̍��W��ύX(�ړ�)���� */
		switch (direction) {
		case 1:
			movey--;	/* ��Ɉړ�(Y���W�����炷) */
			break;
		case 2:
			movey++;	/* ���Ɉړ�(Y���W�𑝂₷) */
			break;
		case 3:
			movex--;	/* ���Ɉړ�(X���W�����炷) */
			break;
		case 4:
			movex++;	/* �E�Ɉړ�(X���W�𑝂₷) */
			break;
		}

		/* �t�B�[���h�O�ɏo�Ă��܂����ꍇ�͍��W���C������ */
		if (movex < 0) {
			movex = 0;	/* ���Ɉړ��������� */
		}
		if (movey < 0) {
			movey = 0;	/* ��Ɉړ��������� */
		}
		if (movex > 4) {
			movex = 4;	/* �E�Ɉړ��������� */
		}
		if (movey > 4) {
			movey = 4;	/* ���Ɉړ��������� */
		}

		/* �t�B�[���h�̃}�X�ڂ̒T�� */
		if (movex != 0 || movey != 0) {	/* �X�^�[�g�n�_(0,0)�ȊO�Ȃ璲���\ */
			if (field[movex][movey] == 0) {	/* ���T���̃}�X�ڂ̂ݑI�������o�� */
				/* �����̗L������͂�����(scanp) */
				printf("Input, Check or Through? (Check:1, Through:Other):");
				scanf("%d", &scanp);

				/* �������� */
				if (scanp == 1) {
					/* �����̍��W������0 or ����1�̍��W�Ɠ����������Ƒ��� */
					if ((movex == ex[0] && movey == ey[0]) || (movex == ex[1] && movey == ey[1])) {
						/* �����ɑ��� */
						gold = gold / 2 + gold % 2;	/* gold�𔼕������A�؂�グ */
						printf("Monster: Gold has become a half.\n");
						field[movex][movey] = -1;	/* �}�X�ڂ̏�Ԃ������ɂ��� */
					} else {
						/* �������� */
						getm = rand() % 8 + 2;	/* ������gold��I��(2-9�̗�������) */
						printf("You get %d gold.\n", getm);
						gold = gold + getm;	/* gold�ɓ���ꂽgold��ǉ����� */
						field[movex][movey] = getm;	/* �}�X�ڂ̏�Ԃ𓾂�ꂽgold�ɂ��� */
					}
				}
			}
		}

		/* �S�[���ɒ��������� */
		if (movex == 4 && movey == 4) {	/* �S�[���n�_(4,4) */
			printf("You have %d gold.\n", gold);
			/* �▭�ȏ�������(���T�������������̂�) */
			if (43 <= gold && gold <= 47) {
				printf("You wins!\n");	/* ���Ȃ��̏����ł� */
			} else {
				printf("You lost!!\n");	/* ���Ȃ��̕����ł� */
			}
			break;	/* �Q�[����while��(�������[�v)���甲���� */
		}
	}
	printf("\n> Thank you for playing! <\n");	/* �֑� */
	exit(0);	/* �I�� */
}