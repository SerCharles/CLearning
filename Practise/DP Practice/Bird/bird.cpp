#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define maxvalue 1000000
int map[1100][110] = { 0 };
int visit[1100][110] = { 0 };
int tube[1100] = { 0 };
int m, n, k;
int whether = 0, time = 0, reach = 0, ans = maxvalue;
int rise[1100], fall[1100];
int min(int a, int b)
{
	if (a > b) return b;
	else return a;
}
int main()
{
	scanf("%d%d%d", &n, &m, &k);
	int i, j;
	for (i = 1; i <= n; i++)
	{
		for (j = 0; j <= m; j++)
		{
			map[i][j] = maxvalue;
		}
	}
	for (i = 1; i <= n; i++)
	{
		scanf("%d%d", &rise[i], &fall[i]);
	}
	for (i = 1; i <= k; i++)
	{
		int x, ydown, yup;
		scanf("%d%d%d", &x, &ydown, &yup);
		tube[i] = x;
		for (j = 0; j <= ydown; j++) visit[x][j] = 1;
		for (j = yup; j <= m; j++) visit[x][j] = 1;
	}
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			if (visit[i][j] == 0)
			{
				int a = maxvalue, b = maxvalue,t,l=m/rise[i],ii;
				if (visit[i - 1][j + fall[i]] == 0 && j + fall[i] <= m) a = map[i - 1][j + fall[i]];
				
				if (j == m)
				{
					for (ii = 1; ii <= l; ii++)
					{
						for (t = 0; t < rise[i]; t++)
						{
							if (visit[i - 1][j - ii*rise[i]+t] == 0 && j - ii*rise[i] + t > 0) b = min(b, map[i - 1][j - ii*rise[i] + t] + ii);
						}
						if (visit[i - 1][j] == 0) b = min(b, map[i - 1][j] + ii);
					}
				}
				else
				{
					for(ii=1;ii<=l;ii++)
					if (visit[i - 1][j - rise[i]*ii] == 0 && j - rise[i]*ii > 0) b = min(b,map[i - 1][j - rise[i]*ii] + ii);
				}
				map[i][j] = min(a, b);
				if (map[i][j] < maxvalue) reach = i;
			}
		}
	}
	if (reach == n)
	{
		whether = 1;
		for (i = 0; i <= m; i++)
		{
			if (map[n][i] < ans) ans = map[n][i];
		}
		printf("%d\n", whether);
		printf("%d", ans);
	}
	else
	{
		whether = 0;
		for (i = 1; i <= k; i++)
		{
			if (reach > tube[i]) time++;
		}
		printf("%d\n", whether);
		printf("%d", time);
	}

	return 0;
}