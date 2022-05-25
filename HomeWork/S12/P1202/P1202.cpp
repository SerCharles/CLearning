#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 1000000007 
int n;
int map[110][2] = { 0 };
int two(int i)
{
	int ans = 1;
	for (int j = 1; j <= i; j++) ans = (ans * 2) % max;
	return ans;
}
int main()
{
	scanf("%d", &n);
	int i;
	for (i = 2; i <= n; i++)
	{
		map[i][0] = (map[i - 1][0] + map[i - 1][1])%max;
		map[i][1] = (two(i - 2) + map[i - 1][0])%max;
	}
	printf("%d", (map[n][0] + map[n][1])%max);
	return 0;
}
