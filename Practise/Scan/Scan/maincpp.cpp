#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char l[11000];
int nmf0=0;
int num=0;
int a[10000] = { 0 };
void handle(int a1, int a2)
{
	int i,time=1,n=0;
	for (i = a2; i >= a1; i--)
	{
		n += time*(l[i] - '0');
		time *= 10;
	}
	a[num++] = n;
}
int main()
{
	FILE* fin;
	fin = fopen("frog.in", "r");
	char c;
	int i;
	while (fscanf(fin,"%c", &c) != EOF)
	{
		l[nmf0++] = c;
	}
	int flag = 1,on=1;
	for (i = 1; i <= nmf0; i++)
	{
		if((l[i] < '0'||l[i] > '9')&&on==1)
		{
			handle(flag, i - 1);
			flag = i - 1;
			on = 0;
		}
		else if (l[i] >= '0'&&l[i] <= '9'&&on == 0)
		{
			on = 1;
			flag = i;
		}
	}
	for (i = 1; i <= num; i++)
	{
		printf("%d ",a[i]);
	}
	while (1);
	return 0;
}