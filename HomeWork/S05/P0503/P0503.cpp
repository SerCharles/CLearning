#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int length=0,sum=0,ans=1;
char str[110];
char ch;
char word[110][110] = { 0 };
int judge(int i)
{
	int  j;
	for (j = 1; j < i; j++)
	{
		if (strcmp(word[j], word[i])==0) return 0;
	}
	return 1;
}
int main()
{
	while (1)
	{
		scanf("%c", &ch);
		if (ch == '\0'||ch=='\n') break;
		else str[length] = ch;
		length++;
	}
	int i;
	sum++;
	int len = 1;
	word[1][0] = str[0];
	for (i = 1; i < length; i++)
	{
		if (str[i]!= ' '&&str[i - 1]!= ' ')
		{
			len++;
			word[sum][len-1] = str[i];
		}
		else if (str[i - 1] == ' '&&str[i] != ' ')
		{
			sum++;
			len = 1;
			word[sum][len-1] = str[i];
		}
	}
	for (i = 2; i <= sum; i++)
	{
		if (judge(i)) ans++;
	}
	printf("%d", ans);
	return 0;
}