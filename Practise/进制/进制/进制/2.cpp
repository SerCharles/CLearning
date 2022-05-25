/*#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n,length,ten=0;
char hex[101];
int sum[101] = { 0 };
int answer[12][101] = { 0 };
int sixteen(int times)
{
	int i,s=1;
	for (i = 1; i <= times; i++)
	{
		s = s * 16;
	}
	return s;
}
void handle(int number,int group)
{
	sum[group]++;
	answer[group][sum[group]] = number % 8;
	if (number / 8)
	{
		handle(number / 8,group);
	}
}
int main()
{
	scanf("%d", &n);
	int i,j;
	for (i = 1; i <= n; i++)
	{
		scanf("%s", hex);
		length = strlen(hex);
		for (j = length - 1; j >= 0; j--)
		{
			int temp;
			if (hex[j] < 60)
			{
				temp = hex[j] - 48;
			}
			else
			{
				temp = hex[j] - 55;
			}
			ten = ten + temp*sixteen(length-j-1);
		}
		handle(ten,i);
		 ten = 0;
	}
	for (i = 1; i <= n; i++)
	{
		for (j = sum[i]; j >= 1; j--)
		{
			printf("%d", answer[i][j]);
		}
		printf("\n");
	}
	//while (1);
	return 0;
}*/