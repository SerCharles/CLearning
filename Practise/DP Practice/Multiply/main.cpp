#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int n, k;
long long int map[50][10] = { 0 };
char list[50];
int min(int a, int b)
{
	if (a > b) return b;
	return a;
}
long long int getnum(int head, int tail)
{
	int ans = 0; int ten = 1; int j;
	for (j = tail; j >= head; j--)
	{
		ans = ans + (list[j] - '0')*ten;
		ten = ten * 10;
	}
	return ans;
}
long long int max(int tail, int head)
{
	long long int m = map[tail - 1][head], i, a;
	for (i = head - 1; i < tail; i++)
	{
		a = map[i][head - 1] * getnum(i, tail-1);
		if (a > m) m = a;
	}
	return m;
}
int main()
{
	scanf("%d%d", &n, &k);
	scanf("%s", list);
	map[0][0] = 1;
	int i, j;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= min(i, k+1); j++)
		{
			map[i][j] = max(i, j);
		}
	}
	printf("%lld", map[n][k+1]);
	while (1);
	return 0;
}