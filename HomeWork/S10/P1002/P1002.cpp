#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int num = 0;
int n;
int map[30] = { 0 };
int main()
{
	scanf("%d", &n);
	int i;
	for (i = 1; i <= n; i++)
	{
		map[0] = 1;
		map[1] = 1;
		map[2] = 2;
		map[3] = 4;
		if(i>=4) map[i] = map[i - 1]+ map[i - 2] + map[i - 3] ;
	}
	printf("%d", map[n]);
	return 0;
}