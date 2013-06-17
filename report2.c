/* 情報処理B report2.c */
/* K&Rスタイルを強いられているんだ */
/* 2013.06.16, TDUCC, 藤代晴嵐 */

#include <stdio.h>	/*標準入出力関数 */
#include <stdlib.h>	/*標準ライブラリ */
#include <time.h>	/*時刻ライブラリ */

/* main関数 */
int main(void)
{
	int movex, movey, gold, ex[2], ey[2], field[5][5], i, j, getm, direction, scanp;
	/*	movex	X座標	自分のいるX座標 */
	/*	movey	Y座標	自分のいるY座標 */
	/*	gold	お金	自分の持っている金額 */
	/*	ex[]	X座標	怪物のいるX座標 */
	/*	ey[]	Y座標	怪物のいるY座標 */
	/*	field[][]	フィールドマス目の状態フラグが入っている配列変数 */
	/*	i	カウンタ	while文でのカウントが入る変数 */
	/*	j	カウンタ	while文でのカウントが入る変数 */
	/*	getm	お金	拾った額が入る変数 */
	/*	direction入力	移動方向の入力が入る変数 */
	/*	scanp	入力	探索するかの有無の入力が入る変数 */

	/* 乱数系列の変更(rand関数の初期化) */
	srand(time(NULL));

	/* フィールドを0で埋める(field初期化) */
	i = 0;
	while (i < 5) {
		j = 0;
		while (j < 5) {
			field[i][j] = 0;	/* フィールドを0に設定 */
			j++;
		}
		i++;
	}

	/* 自分の場所を設定する(movex,moveyの初期化) */
	movex = 0;	/* 自分のX座標(スタート地点) */
	movey = 0;	/* 自分のY座標(スタート地点) */

	/* 自分の持っている金額を設定する(goldの初期化) */
	gold = 0;	/* 自分の持っている金額(開始時点) */

	/* 怪物0の場所を決める(ex[0],ey[0]の初期化) */
	do {
		ex[0] = rand() % 5;	/* 怪物0のX座標を選ぶ(0-4の乱数生成) */
		ey[0] = rand() % 5;	/* 怪物0のY座標を選ぶ(0-4の乱数生成) */
	} while (ex[0] == 0 && ey[0] == 0);	/* スタート地点(0,0)なら選びなおす */

	/* 怪物1の場所を決める(ex[1],ey[1]の初期化) */
	do {
		ex[1] = rand() % 5;	/* 怪物1のX座標を選ぶ(0-4の乱数生成) */
		ey[1] = rand() % 5;	/* 怪物1のY座標を選ぶ(0-4の乱数生成) */
	} while ((ex[1] == 0 && ey[1] == 0) || (ex[1] == ex[0] && ey[1] == ey[0]));
	/* スタート地点(0,0)もしくは怪物0の場所(ex[0],ey[0])なら選びなおす */

	/* ゲーム開始(無限ループ) */
	while (1){
		/* フィールドを表示する */
		i = 0;
		while (i < 5) {
			j = 0;
			while (j < 5) {
				if (i == movey && j == movex) {	/* 自分のいる座標なら */
					printf(" 1");	/* 自分(1)を表示する */
				} else {	/* 自分がいない座標なら */
					printf("%2d", field[j][i]);	/* フィールドの状態を表示していく */
				}
				j++;
			}
			printf("\n");	/* 改行(次の行) */
			i++;
		}
		printf("\n");	/* report02-tue4.pdfの表示例通りにするため */

		/* 移動方向を入力させる(direction) */
		printf("Input, where you going? (Up:1, Down:2, Left:3, Right:4): ");
		scanf("%d", &direction);

		/* 入力された移動方向結果に従って自分の座標を変更(移動)する */
		switch (direction) {
		case 1:
			movey--;	/* 上に移動(Y座標を減らす) */
			break;
		case 2:
			movey++;	/* 下に移動(Y座標を増やす) */
			break;
		case 3:
			movex--;	/* 左に移動(X座標を減らす) */
			break;
		case 4:
			movex++;	/* 右に移動(X座標を増やす) */
			break;
		}

		/* フィールド外に出てしまった場合は座標を修正する */
		if (movex < 0) {
			movex = 0;	/* 左に移動しすぎた */
		}
		if (movey < 0) {
			movey = 0;	/* 上に移動しすぎた */
		}
		if (movex > 4) {
			movex = 4;	/* 右に移動しすぎた */
		}
		if (movey > 4) {
			movey = 4;	/* 下に移動しすぎた */
		}

		/* フィールドのマス目の探索 */
		if (movex != 0 || movey != 0) {	/* スタート地点(0,0)以外なら調査可能 */
			if (field[movex][movey] == 0) {	/* 未探索のマス目のみ選択肢を出す */
				/* 調査の有無を入力させる(scanp) */
				printf("Input, Check or Through? (Check:1, Through:Other):");
				scanf("%d", &scanp);

				/* 調査する */
				if (scanp == 1) {
					/* 自分の座標が怪物0 or 怪物1の座標と同じ→怪物と遭遇 */
					if ((movex == ex[0] && movey == ey[0]) || (movex == ex[1] && movey == ey[1])) {
						/* 怪物に遭遇 */
						gold = gold / 2 + gold % 2;	/* goldを半分失う、切り上げ */
						printf("Monster: Gold has become a half.\n");
						field[movex][movey] = -1;	/* マス目の状態を怪物にする */
					} else {
						/* お金入手 */
						getm = rand() % 8 + 2;	/* 得られるgoldを選択(2-9の乱数生成) */
						printf("You get %d gold.\n", getm);
						gold = gold + getm;	/* goldに得られたgoldを追加する */
						field[movex][movey] = getm;	/* マス目の状態を得られたgoldにする */
					}
				}
			}
		}

		/* ゴールに着いた判定 */
		if (movex == 4 && movey == 4) {	/* ゴール地点(4,4) */
			printf("You have %d gold.\n", gold);
			/* 絶妙な勝利条件(何探索したかったのか) */
			if (43 <= gold && gold <= 47) {
				printf("You wins!\n");	/* あなたの勝ちです */
			} else {
				printf("You lost!!\n");	/* あなたの負けです */
			}
			break;	/* ゲームのwhile文(無限ループ)から抜ける */
		}
	}
	printf("\n> Thank you for playing! <\n");	/* 蛇足 */
	exit(0);	/* 終了 */
}