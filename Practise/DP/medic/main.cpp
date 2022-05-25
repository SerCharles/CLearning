#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
int time, number,answer=0;
struct swadia
{
	int cost, value;
}medicine[110];
int map[110][1010] = { 0 };
int max(int a, int b)
{
	if (a > b) return a;
	else return b;
}
int main()
{
	int i,j;
	scanf("%d%d", &time, &number);
	for (i = 1; i <= number; i++)
	{
		scanf("%d%d", &medicine[i].cost, &medicine[i].value);
	}
	for (i = 1; i <= number; i++)
	{
		for (j = 1; j <= time; j++)
		{
			if (j < medicine[i].cost)
			{
				map[i][j] = map[i - 1][j];
			}
			else
			{
				map[i][j] = max(map[i - 1][j], map[i - 1][j - medicine[i].cost] + medicine[i].value);//1£º²»·Å 2£º·Å
				answer = max(answer, map[i][j]);
			}
		}
	}
	printf("%d", answer);
	return 0;
}