#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
int num,m,n;
int a[12][12] = { 0 };
int main()
{
	int i,j;
	for (i = 1; i <= 10; i++)
	{
		a[i][1] = 1;
		a[1][i] = 1;
		a[0][i] = 1;
	}
	for (i = 2; i <= 10; i++)
	{
		for (j = 2; j <= 10; j++)
		{

			if (i < j) a[i][j] = a[i][i];
				if (i >= j) a[i][j] = a[i][j - 1] + a[i - j][j];
		}
	}
	scanf("%d", &num);
	for (i = 1; i <= num; i++)
	{
		scanf("%d%d", &m, &n);
		printf("%d\n", a[m][n]);
	}
	while (1);
	return 0;
}