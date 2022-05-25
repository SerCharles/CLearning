#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int map[501][100001] = { 0 };
int value[501] = { 0 }, weight[501] = { 0 };
int n, m,ans=-1;
int max(int a, int b)
{
	if (a > b) return a;
	return b;
}
int main()
{
	scanf("%d%d", &n, &m);
	int i,j;
	for (i = 1; i <= n; i++)
	{
		scanf("%d%d", &weight[i],&value[i]);
	}
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			if (j >= weight[i]) map[i][j] = max(map[i - 1][j], map[i - 1][j - weight[i]] + value[i]);
			else map[i][j] = map[i - 1][j];
		}
	}
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			if (map[i][j] > ans) ans = map[i][j];
		}
	}
	printf("%d", ans);
	return 0;
}