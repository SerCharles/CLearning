#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int list[110] = { 0 }, map[110][110] = { 0 }, rank[110] = { 0 };
int num = 0,ans=-2837636;
int max(int i)
{
	int j;
	int mx = -3937646;
	for (j = 1; j <= rank[i]; j++)
	{
		if (map[i - 1][j] > mx) mx = map[i - 1][j];
	}
	return mx + 1;
}
int main()
{
	int i,j;
	int a = 1;
	char y;
	while (1)
	{
		int a;
		char s;
		scanf("%d", &a);
		num++;
		list[num] = a;
		s = getchar();
		if (s == EOF) break;
	}
	for (i = 1; i <= num; i++)
	{
		for (j = 1; j <= num; j++)
		{
			if (list[i] >= list[j]) rank[i]++;
		}
	}
	for (i = 1; i <= num; i++)
	{
		for (j = 1; j <= num; j++)
		{
			if (rank[i] == j) map[i][j] = max(i);
			else map[i][j] = map[i - 1][j];
		}
	}
	for (i = 1; i <= num; i++)
	{
		if (map[num][i] > ans) ans = map[num][i];
	}
	printf("%d", ans);

	return 0;
}