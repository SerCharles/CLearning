#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
int volume,number,answer=0;
int item[32];
int map[32][20020] = { 0 };
int max(int a, int b)
{
	if (a > b) return a;
	else return b;
}
int main()
{
	scanf("%d", &volume);
	scanf("%d", &number);
	int i,j;
	for (i = 1; i <= number; i++)
	{
		scanf("%d", &item[i]);
	}
	for (i = 1; i <= number; i++)
	{
		for (j = 1; j <= volume; j++)
		{
			if (j < item[i])
			{
				map[i][j] = map[i - 1][j];
			}
			else
			{
				map[i][j] = max(map[i - 1][j - item[i]]+item[i], map[i - 1][j]);//收益=体积
				answer = max(answer, map[i][j]);
			}
		}
	}
	printf("%d", volume-answer);
	return 0;
}