#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int map[220][220] = { 0 };
int list[210] = { 0 };
int n, k;
int ans = 398732;
int main()
{
	scanf("%d%d", &n, &k);
	int i, j,t,a,b;
	for (i = 1; i <= n; i++)
	{
		scanf("%d%d", &a, &b);
		list[a] = b;
	}
	for (i = 1; i <= 100; i++)
	{
		for (j = 1; j <= 200; j++)
		{
			if (i == 1) map[i][j] = 0;
			else map[i][j] = 398732;
		}
	}

	for (i = 2; i <= n - k; i++)
	{
		for (j = 1; j <= 200; j++)
		{
			if (list[j] != 0)
			{
				for (t = 1; t < j; t++)
				{
					int sum=398732;
					if (list[t] != 0) sum = map[i - 1][t] + abs(list[t] - list[j]);
					if (sum < map[i][j]) map[i][j] = sum;
				}
			}
		}
	}
	for (i = 1; i <= 200; i++)
	{
		if (map[n - k][i] < ans) ans = map[n - k][i];
	}

	printf("%d", ans);
	while (1);
	return 0;
}