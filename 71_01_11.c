#include<stdio.h>
#include<stdlib.h>
/*
int main(void)
{
	char* a = "0";
	int s;

	for(s = 0; s < 10; s++)
	{
		printf("%d\t%s\n", *a, a);
		(*a)++;
	}
	exit(0);
}
*/
int main(void)
{
	char s[256], buf[256];
	int cnt;

	for(;;)
	{
		gets(buf);
		if (sscanf(buf, "%[^\n]%*c", &s) != 1) break;
		for(cnt = 0; cnt < strlen(s); cnt++) if (s[cnt] >= 'a' && s[cnt] <= 'z') s[cnt] += 'A' - 'a';
		printf("%s", s);
	}
	exit(0);
}
