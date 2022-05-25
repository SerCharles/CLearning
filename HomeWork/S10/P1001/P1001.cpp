#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int A(int x, int y);
int main()
{
	int x, y;
	scanf("%d%d", &x, &y);
	printf("%d", A(x, y));
	return 0;
}
int A(int x, int y)
{
	if (x == 0)
	{
		return y + 1;
	}
	else if (x > 0 && y == 0)
	{
		return A(x - 1, 1);
	}
	else
	{
		return A(x - 1, A(x, y - 1));
	}
}