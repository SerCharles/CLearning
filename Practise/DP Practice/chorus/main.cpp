#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int n,ans=140226;
int list[110] = { 0 }, map[110] = { 0 }, left[110][110] = { 0 }, right[110][110] = { 0 };
int dp_l(int border)
{
	int mid = list[border],i,j,num=0;
	for (i = 1; i < border; i++)
	{
		for (j = 0; j < mid; j++)
		{
			left[i][j] = left[i - 1][j];
			if (left[i][j] > num) num = left[i][j];
		}
		if (list[i] < mid)
		{
			for (j = 0; j < list[i]; j++)
			{
				if (left[i - 1][j] + 1 > left[i][list[i]]) left[i][list[i]] = left[i - 1][j] + 1;
				if (left[i][list[i]] > num) num = left[i][list[i]];
			}
		}
	}
	return num;
}
int dp_r(int border)
{
	int mid = list[border], i, j, num = 0;
	for (i = border+1; i <= n; i++)
	{
		for (j = mid; j >= 0; j--)
		{
			right[i][j] = right[i - 1][j];
			if (right[i][j] > num) num = right[i][j];
		}
		if (list[i] < mid)
		{
			for (j = mid; j > list[i]; j--)
			{
				if (right[i - 1][j] + 1 > right[i][list[i]]) right[i][list[i]] = right[i - 1][j] + 1;
				if (right[i][list[i]] > num) num = right[i][list[i]];
			}
		}
	}
	return num;
}
int main()
{
	scanf("%d", &n);
	int i,j,ii,jj;
	for (i = 1; i <= n; i++)
	{
		int a;
		scanf("%d", &a);
		list[i] = a - 130;
	}
	for (i = 1; i <= n; i++)
	{
		for (j = 0; j <= 100; j++)
		{
			left[i][j] = 0; right[i][j] = 0;
	    }
		map[i] = n - 1 - dp_l(i) - dp_r(i);
	}
	for (i = 1; i <= n; i++) if (ans > map[i]) ans = map[i];
	printf("%d", ans);
	while (1); return 0;
}