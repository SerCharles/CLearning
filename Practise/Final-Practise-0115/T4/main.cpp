#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int n, k;
#define MAXN 100000000
bool whether[MAXN] = { 0 };
int num[30] = { 0 };
int visit[30] = { 0 };
int ans=0;
void get_num(int s);
void DFS(int step,int sum,int back);
int main()
{
	
	scanf("%d%d", &n, &k);
	int i, sum=0;
		for (i = 1; i <= n; i++)
		{
			scanf("%d", &num[i]);
			sum += num[i];
		}
		get_num(sum);
		DFS(0,0,0);
		printf("%d", ans);
		return 0;
}
void get_num(int s)
{
	whether[1] = 1;
	for (int i = 1; i <= s; i++)
	{
		if (whether[i] == 0)
		{
			for (int j = 2; j <= s / i; j++)
			{
				whether[i*j] = 1;
			}
		}
	}
}
void DFS(int step,int sum,int back)
{
	if (step == k)
	{
		if (whether[sum] == 0) ans++;
	}
	else
	{
		int i;
		for (i = back+1; i <= n; i++)
		{
			if (visit[i] == 0)
			{
				visit[i] = 1;
				DFS(step + 1, sum + num[i],i);
				visit[i] = 0;
			}
		}
	}
}