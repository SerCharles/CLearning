#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
const int MAXN = 13;
int n, whether = 1;
double matrix[MAXN][MAXN];
double answer[MAXN] = { 0 };
void input();
void del();
void clean(int i);
void getans();
void output();
int main()
{
	input();
	del();
	getans();
	output();
	return 0;
}
void input()
{
	scanf("%d", &n);
	int i, j;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			scanf("%lf", &matrix[i][j]);
		}
	}
	for (i = 1; i <= n; i++)
	{
		scanf("%lf", &matrix[i][n + 1]);
	}
}
void del()
{
	int i, j, k;
	for (i = 1; i < n; i++)
	{
		clean(i);
		for (j = i + 1; j <= n; j++)
		{
			for (k = n+1; k >= i; k--)
			{
				if (matrix[j][i] == 0) break;
				matrix[j][k] = matrix[j][k] - matrix[i][k];
			}
		}
	}
}
void clean(int i)
{
	int j, k;
	for (k = i; k <= n; k++)
	{
		for (j = n+1; j >= i; j--)
		{
			if (matrix[k][i] == 0) break;
			matrix[k][j] = matrix[k][j] / matrix[k][i];
		}
	}
}
void getans()
{
	int i, j;
	for (i = n; i >= 1; i--)
	{
		if (matrix[i][i] == 0)
		{
			whether = 0;
			return;
		}
		answer[i] = matrix[i][n + 1] / matrix[i][i];
		for (j = n - 1; j >= 1; j--)
		{
			matrix[j][n + 1] = matrix[j][n + 1] - matrix[j][i] * answer[i];
		}
	}
}
void output()
{
	int i;
	if (whether == 1)
	{
		for (i = 1; i <= n; i++)
		{
			printf("%.2f", answer[i]);
			printf("\n");
		}
	}
	else
	{
		printf("Error");
	}
}