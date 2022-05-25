#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int num=0,max=0,ans=0,ans2=100001;
int list[5000] = { 0 };
int map[5010][10010] = { 0 };
int map2[5010][10010] = { 0 };
int maximum(int i, int j, int height);
int maximum2(int i, int height);
int main()
{
		scanf("%d", &num);
		int i, j;
		for (i = 1; i <= num; i++)
		{
			int a;
			scanf("%d", &a);
			if (a > max) max = a;
			list[i] = a;
		}
	for (i = 1; i <= num; i++)
	{
		for (j = 1; j <= max; j++)
		{
			if (j < list[i]) map[i][j] = map[i - 1][j];
			if (j > list[i]) map[i][j] = map[i - 1][j];
			if (j == list[i]) map[i][j] = maximum(i, j, list[i])+1;
			if (map[i][j] > ans) ans = map[i][j];
	    }
	}
	for (i = 1; i <= num; i++)
	{
		for (j = 1; j <= max; j++)
		{
			if (i == 1)
			{
              map2[i][j] = 1;
			}
			else
			{
				if (j > list[i]) map2[i][j] = map2[i - 1][j] + 1;
				if (j < list[i]) map2[i][j] = map2[i - 1][j] + 1;
				if (j == list[i])
				{
					map2[i][j] = maximum2(i, list[i]);
				}
			}
		}
	}
	for (i = 1; i <= max; i++)
	{
		if (map2[num][i] < ans2) ans2 = map2[num][i];
	}
	printf("%d %d", ans,ans2);
	while (1);
	return 0;
}
int maximum(int i, int j, int height)
{
	int m= 0;
	int k;
	for (k = height; k <= max+1; k++)
	{
		if (map[i - 1][k] > m) m = map[i - 1][k];
	}
	return m;
}
int maximum2(int i, int height)
{
	int m = 100001;
	for (int k = 1; k <= max; k++)
	{
		int temp;
		if (k < height) temp = map2[i - 1][k] + 1;
		else temp = map2[i - 1][k];
		if (temp < m) m = temp;
	}
	return m;
}