#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char l[10];
int list[10] = { 0 };
int length;
int answer = 0;
int judge1();
int judge();
int judge2(int a[]);
int main()
{
	int i;
	gets(l);
	length = strlen(l);
	for (i = 1; i <= length; i++) list[i] = l[i - 1] - '0';
	if (judge1())
	{
		if (judge()) answer = 1;
	}
	if (answer == 1) printf("yes");
	else printf("no");
	return 0;
}
int judge1()
{
	int i;
	int m[11] = { 0 };
	for (i = 1; i <= length; i++)
	{
		if (m[list[i]] == 1) return 0;
		m[list[i]] = 1;
	}
	return 1;
}
int judge()
{
	int visit[10] = { 0 };
	int flag = 1;
	int i;
	visit[flag] = 1;
	for (i = 1; i <= length; i++)
	{
		flag = (flag + list[flag]) % length;
		if (flag == 0) flag = length;
		visit[flag] = 1;
	}
	if (judge2(visit) && flag == 1) return 1;
	else return 0;
}
int judge2(int a[])
{
	int i;
	for (i = 1; i <= length; i++)
	{
		if (a[i] == 0) return 0;
	}
	return 1;
}