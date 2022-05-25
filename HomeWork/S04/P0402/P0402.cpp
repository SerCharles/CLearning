#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
int number[20] = { 0 };
int n;
int main()
{
	int i;
	number[0] = 1;
	number[1] = 3;
	scanf("%d", &n);
	for (i = 2; i <= n; i++)
	{
		number[i] = 4 * number[i - 1] - number[i - 2];
	}
	printf("%d", number[n]);
	return 0;
}