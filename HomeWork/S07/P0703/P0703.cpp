#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
bool map1[5000000] = { 0 }, map2[5000000] = { 0 };
int min, max;
void judge1();
int judge2(int num);
int divide(int num, int temp[]);
int main()
{
	int i;
	scanf("%d%d", &min, &max);
	judge1();
	for (i = 0; i <= max; i++)
	{
		map2[i]=judge2(i);
	}
	for (i = min; i <=max; i++)
	{
		if ( map1[i]==0&&map2[i] == 0) printf("%d ", i);
	}
	return 0;
}
void judge1()
{
	map1[0] = 1; map1[1] = 1;
	int i,j;
	for (i = 2; i <= max; i++)
	{
		if (map1[i] == 0)
		{
			for (j = 2; j <= max / i; j++)
			{
				map1[j*i] = 1;
			}
		}
	}
}
int judge2(int num)
{
	if (num == 0) return 0;
	int temp[12] = { 0 };
	int length = 0;
	length=divide(num,temp);
	int i;
	for (i = 1; i <= length / 2; i++)
	{
		if (temp[i] != temp[length + 1 - i]) return 1;
	}
	return 0;
}
int divide(int num, int temp[])
{
	int i = 0;
	while (num != 0)
	{
		i++;
		temp[i] = num % 10;
		num = (num - temp[i] )/10;
	}
	return i;
}