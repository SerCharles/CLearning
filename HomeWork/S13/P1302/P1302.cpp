#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int whether[41] = { 0 };
int list[21] = { 0 };
int visit[21] = { 0 };
int n;
int ans = 0;
void judge();
void DFS(int step);
int main()
{
	judge();
	scanf("%d", &n);
	list[1] = 1;
	visit[1] = 1;
	if (n%2==0)
	{
		DFS(1);
	}
	if (ans == 0||n%2==1) printf("No Answer");
	return 0;
}
void judge()
{
	int i,j;
	whether[1] = 1; whether[0] = 1;
	for (i = 2; i <= 40; i++)
	{
		for (j = 2; j < i; j++)
		{
			if (i%j == 0)
			{
				whether[i] = 1;
			}
		}
	}
}
void DFS(int step)
{
	if (step==n)
	{
		if (whether[list[step] + 1] == 0)
		{
			for (int i = 1; i <= n; i++)
			{
				printf("%d ", list[i]);
			}
			printf("\n");
			ans = 1;
		}
	}
	else
	{
		int init, i;
		if (list[step] % 2 == 0) init = 1;
		else init = 2;
		for (i = init; i <= n; i += 2)
		{
			int nova = list[step] + i;
			if (visit[i] == 0 && whether[nova] == 0)
			{
				list[step + 1] = i;
				visit[i]=1;
				DFS(step + 1);
				list[step + 1] = 0;
				visit[i] = 0;
			}
		}
	}
}