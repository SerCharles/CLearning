#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char c[110];
int list[110];
int map[110][110][110] = { 0 }; //中值，前驱，后继(奇数表）
int mapx[110][110][110] = { 0 };
int n,ansmin=20000000;
int main()
{
	scanf("%s", c);
	int i,j,k;
	n = strlen(c);
	for (i = 0; i < strlen(c); i++)  list[i + 1] = c[i] - 'A' + 1;
	//奇数表
	for (i = 1; i <= n; i++) 
	{
		int middle = i;
		map[middle][middle][middle] = 0;
		int flag = 1;
		while (middle - flag > 0 || middle + flag <= n)
		{
			
			if (middle - flag > 0 && middle + flag <= n)
			{
				map[middle][middle - flag + 1][middle + flag] = map[middle][middle - flag + 1][middle + flag - 1] + 1;
				map[middle][middle - flag][middle + flag - 1] = map[middle][middle - flag + 1][middle + flag - 1] + 1;
				if (list[middle + flag] == list[middle - flag]) map[middle][middle - flag][middle + flag] = map[middle][middle - flag + 1][middle + flag - 1];
				else map[middle][middle - flag][middle + flag] = map[middle][middle - flag + 1][middle + flag - 1]+1;
			}
			if (middle - flag <= 0)
			{
				map[middle][1][middle + flag] = map[middle][1][middle + flag - 1] + 1;
			}
			if (middle + flag > n)
			{
				map[middle][middle - flag][n] = map[middle][middle - flag + 1][n] + 1;
			}
			flag++;
		}
	}
	//偶数表
	for (i = 2; i <= n; i++) 
	{
		int middle = i;
		if (list[middle - 1] == list[middle])
		{
			mapx[middle][middle - 1][middle] = 0;
		}
		else
		{
			mapx[middle][middle - 1][middle] = 1;
		}
		int flag = 2;
		while (middle - flag > 0 || middle + flag-1 <= n)
		{

			if (middle - flag > 0 && middle + flag-1 <= n)
			{
				mapx[middle][middle - flag + 1][middle + flag-1] = mapx[middle][middle - flag + 1][middle + flag - 2] + 1;
				mapx[middle][middle - flag][middle + flag - 2] = mapx[middle][middle - flag + 1][middle + flag - 1] + 1;
				if (list[middle + flag-1] == list[middle - flag]) mapx[middle][middle - flag][middle + flag-1] = mapx[middle][middle - flag + 1][middle + flag - 2];
				else mapx[middle][middle - flag][middle + flag-1] = mapx[middle][middle - flag + 1][middle + flag - 2] + 1;
			}
			if (middle - flag <= 0)
			{
				mapx[middle][1][middle + flag-1] = mapx[middle][1][middle + flag - 2] + 1;
			}
			if (middle + flag-1 > n)
			{
				mapx[middle][middle - flag][n] = mapx[middle][middle - flag + 1][n] + 1;
			}
			flag++;
		}
	}

	for (i = 1; i <= n; i++)
	{
		if (map[i][1][n] < ansmin) ansmin = map[i][1][n];
    }
	for (i = 2; i <= n; i++)
	{
		if (mapx[i][1][n] < ansmin) ansmin = mapx[i][1][n];
	}
	printf("%d", ansmin);
	return 0;
}