/* 情報処理B report2ex.c */
/* 課題ぶっぱスタイル (BSD/Allman Style) */
/* VisualStudio2012 GCC4.2.1 Clang3.1 で動作確認 */
/* 2013.06.16, 10RU004, 石橋祥太 */

#include <stdio.h>	/*標準入出力関数 */
#include <stdlib.h>	/*標準ライブラリ */
#include <string.h>	/*文字列ライブラリ */
#include <time.h>	/*時刻系ライブラリ */

/* 定数宣言 */
#define XMAX 5	/* フィールドのX大きさ */
#define YMAX 5	/* フィールドのY大きさ */
#define GMIN 43	/* 勝利条件下限 */
#define GMAX 47	/* 勝利条件上限 */

/* 関数宣言 */
void input(char *, long);

int main(int argc, char *argv[])
{
	char movex = 0, movey = 0, ex[2], ey[2], field[XMAX * YMAX] = {0}, i, j, getm, direc[2] = {0}, scanp[2] = {0};
	short gold = 0;
	/*	movex	X座標	自分のいるX座標 */
	/*	movey	Y座標	自分のいるY座標 */
	/*	ex[]	X座標	怪物のいるX座標 */
	/*	ey[]	Y座標	怪物のいるY座標 */
	/*	field[]	フィールド状態フラグが入っている配列変数 */
	/*	i	カウンタ	カウントが入る変数 */
	/*	j	カウンタ	カウントが入る変数 */
	/*	getm	お金	拾った額が入る変数 */
	/*	direc[]	入力	移動方向の入力が入る変数 */
	/*	scanp[]	入力	探索するかの有無の入力が入る変数 */
	/*	gold	お金	自分の持っている金額 */

	srand(time(NULL));	/* 乱数系列の変更(rand関数の初期化) */

	/* 怪物の場所を決める(ex,eyの初期化)この方法で一撃にてスタート地点(0,0)以外で怪物が同じマスにならないように決定する */
	ex[0] = rand() % XMAX;	/* 怪物0のX座標を選ぶ(0-4の乱数生成) */
	ey[0] = rand() % (YMAX - (ex[0] == 0)) + (ex[0] == 0);	/* 怪物0のY座標を選ぶ(0-4の乱数生成、怪物0のX座標が0なら1-4の乱数生成) */
	ex[1] = rand() % XMAX;	/* 怪物1のX座標を選ぶ(0-4の乱数生成) */
	ey[1] += ey[0] <= (ey[1] = rand() % (YMAX - (ex[1] == ex[0]) - (ex[1] == 0)) + (ex[1] == 0)) && ex[1] == ex[0];
	/* 怪物1のY座標を選ぶ(怪物1のX座標上にスタート地点・怪物0がいると選べるY座標分がどんどん減る) */

	for(;;)	/* ゲーム開始(無限ループ) */
	{
		/* フィールドを表示する */
		for (i = 0; i < YMAX; printf("\n") && i++)	/* フィールドの状態を表示していく */
			for (j = 0; j < XMAX; j++ == movex && i == movey ? printf(" 1") : printf("%2d", field[j + i * XMAX - 1]));

		/* 移動方向を入力させる(direc) */
		printf("\nInput, where you going? (Up:1, Down:2, Left:3, Right:4): ");
		input(direc, 2);

		/* 入力された移動方向結果に従って自分の座標を変更(移動)する */
		movey -= direc[0] == '1';	/* 上に移動(Y座標を減らす) */
		movey += direc[0] == '2';	/* 下に移動(Y座標を増やす) */
		movex -= direc[0] == '3';	/* 左に移動(X座標を減らす) */
		movex += direc[0] == '4';	/* 右に移動(X座標を増やす) */

		/* フィールド外に出てしまった場合は座標を修正する */
		if (movex < 0) movex = 0;	/* 左に移動しすぎた */
		if (movey < 0) movey = 0;	/* 上に移動しすぎた */
		if (movex >= XMAX) movex = XMAX - 1;	/* 右に移動しすぎた */
		if (movey >= YMAX) movey = YMAX - 1;	/* 下に移動しすぎた */

		/* フィールドのマス目の探索 */
		if ((movex != 0 || movey != 0) && field[movex + movey * XMAX] == 0)	/* スタート地点(0,0)以外なら調査可能 未探索のマス目のみ選択肢を出す */
		{
			/* 調査の有無を入力させる(scanp) */
			printf("Input, Check or Through? (Check:1, Through:Other):");
			input(scanp, 2);

			if (scanp[0] == '1')	/* 調査する */
			{
				if ((movex == ex[0] && movey == ey[0]) || (movex == ex[1] && movey == ey[1]))	/* 自分の座標が怪物0 or 怪物1の座標と同じ→怪物と遭遇 */
				{	/* 怪物に遭遇 */
					gold = gold / 2 + gold % 2;	/* goldを半分失う、切り上げ */
					printf("Monster: Gold has become a half.\n\n");
					field[movex + movey * XMAX] = -1;	/* マス目の状態を怪物にする */
				}
				else
				{	/* お金入手 */
					printf("You get %d gold.\n\n", getm = rand() % 8 + 2);	/* 得られるgoldを選択(2-9の乱数生成)、表示 */
					gold += field[movex + movey * XMAX] = getm;	/* マス目の状態を得られたgoldにし、goldに得られたgoldを追加する */
				}
			}
		}

		/* ゴールに着いた判定 */
		if (movex == (XMAX - 1) && movey == (YMAX - 1))
		{
			printf("You have %d gold.\n", gold);
			/* 絶妙な勝利条件(何探索したかったのか) */
			if (GMIN <= gold && gold <= GMAX)
			     printf("You wins!\n");	/* あなたの勝ちです */
			else printf("You lost!!\n");	/* あなたの負けです */
			break;	/* ゲームのfor文(無限ループ)から抜ける */
		}
	}
	printf("\n> Thank you for playing! <\n");	/* 蛇足 */
	return 0;	/* 終了 */
}

void input(char s[], long len)	/* 入力関数 */
{
	fgets(s, len, stdin);

	if (strchr(s, '\n') != 0) s[strlen(s) - 1] = '\0';
	else while (getchar() != '\n');

	return;
}