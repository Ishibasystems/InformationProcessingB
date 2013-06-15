//この課題は 通常課題 です。

#include<stdio.h>

void rot9file(FILE *);
//	ファイルをrot9処理する関数

void rot9(unsigned char []);
//	文字列をrot9処理する関数

void rot(char *);
//	一文字rot9処理する関数

int main(int argc, char *argv[])
{
	int size, cnt;
	//	size	rot9される文字数
	//	cnt		コマンド引数のファイルカウンタ

	char s[256], buf[81];
	//	s	rot9する文字列
	//	buf	入力の文字列(一行取り込み用)

	FILE *hFile;
	//	hFile	ファイルハンドル

	if (argc > 1)
	{
		for(cnt = 1; cnt < argc; cnt++)
		{
			hFile = fopen(argv[cnt], "rb+");
			if (hFile == NULL) continue;
			rot9file(hFile);
			printf("ROT9| %s\n", argv[cnt]);
			fclose(hFile);
		}
	}
	else
	{
		for(;;)
		{
			printf("press a string to encrypt : \n");
			gets(buf);
			if (sscanf(buf, "%[^\n]%*c", s) != 1) break;

			size = strlen(s);
			if (size > 80) s[80] = '\0';

			rot9(s);
			printf("%s\n", s);

			rot9(s);
			printf("%s\n", s);

			rot9(s);
			printf("%s\n\n", s);
		}
	}
	exit(0);
}

void rot9file(FILE *file)
{
	unsigned char buf[2];
	//	buf	入力の文字列(一文字取り込み用)

	fseek(file, 0, SEEK_SET);
	for(;;)
	{
		if(feof(file) != 0) break;
		if(fread(buf, sizeof(unsigned char), 1, file) != 1) break;
		if(feof(file) != 0) break;

		if ((buf[0] >= 0x81 && buf[0] <= 0x9f) || (buf[0] >= 0xe0 && buf[0] <= 0xfc))
		{
			fseek(file, 1, SEEK_CUR);
			continue;
		}
		fseek(file, -1, SEEK_CUR);
		rot(buf);
		fwrite(buf, sizeof(unsigned char), 1, file);
		fseek(file, 0, SEEK_CUR);
	}
	return;
}

void rot9(unsigned char s[])
{
	int cnt;
	//	cnt 	文字列カウンタ

	for(cnt = 0; cnt < strlen(s); cnt++)
	{
		if ((*(s + cnt) >= 0x81 && *(s + cnt) <= 0x9f) || (*(s + cnt) >= 0xe0 && *(s + cnt) <= 0xfc)) cnt++;
		else rot(s + cnt);
	}
	return;
}

void rot(char *s)
{
	if ((*s >= 'a' && *s <= '{') || (*s >= 'A' && *s <= '['))
	{
		if ((*s > 'R' && *s < '\\') || (*s > 'r' && *s < '|')) *s -= 18;
		else *s += 9;
	}
	return;
}
