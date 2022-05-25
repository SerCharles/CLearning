#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int max, n,ans=0;
int map[26][31000] = { 0 },list[30],value[30];
int maxi(int a, int b)
{
	if (a > b) return a;
	else return b;
}
int main()
{

	scanf("%d%d",&max,&n);
	int i,j,a,b;
	for (i = 1; i <= n; i++)
	{
		scanf("%d%d", &a, &b);
		value[i] = a;
		list[i] = a*b;
	}
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= max; j++)
		{
			if (j >= value[i]) map[i][j] = maxi(map[i - 1][j], map[i - 1][j - value[i]] + list[i]);
			else map[i][j] = map[i - 1][j];
			if (map[i][j] > ans) ans = map[i][j];
		}
	}
	printf("%d", ans);
	return 0;
}