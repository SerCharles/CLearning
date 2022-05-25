#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char s1[1020] = { 0 }, s2[1020] = { 0 };
int ans = 0;
int judge(char str1[], char str2[]);
int max(int a, int b);
int main()
{
	gets(s1);
	gets(s2);
	ans=judge(s1, s2);
	printf("%d", ans);

	return 0;
}
int judge(char str1[], char str2[])
{
	int len;
	len = max(strlen(str1), strlen(str2));
	int i;
	for (i = 0; i < len; i++)
	{
		if (str1[i] != str2[i]) return str1[i] - str2[i];
	}
	return 0;
}
int max(int a, int b)
{
	if (a > b) return a;
	else return b;
}