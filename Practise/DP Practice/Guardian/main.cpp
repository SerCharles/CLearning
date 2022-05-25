#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int map[1100][1100] = { 0 };
int magic, length, time,maximum=0,minimum=1000000,win=0;
int max(int i, int j)
{
	int ans = 0,a;
	if (magic - j >= 10)
	{
		a = map[i - 1][j + 10]+60;
		if (a > ans) ans = a;
	}
	if (j >= 4)
	{
		a = map[i - 1][j -4];
		if (a > ans) ans = a;
	}
	a = map[i - 1][j]+17;
	if (a > ans) ans = a;
	return ans;
}

int main()
{
	scanf("%d%d%d", &magic, &length, &time);
	int i,j;
	for (i = 1; i <= time; i++)
	{
		for (j = 0; j <= magic; j++)
		{
			map[i][j] = max(i, j);
		}
	}
	for (i = 1; i <= time; i++)
	{
		if (win == 1) break;
		for (j = 0; j <= magic; j++)
		{
			if (win == 1) break;
			if (map[i][j] > maximum) maximum = map[i][j];
			if (map[i][j] >= length)
			{
				win = 1;
				minimum = i;
				break;
			}
		}
	}
	if (win == 1)
	{
		printf("Yes\n");
		printf("%d", minimum);
	}
	else
	{
		printf("No\n");
		printf("%d", maximum);
	}
	while (1);
	return 0;
}
