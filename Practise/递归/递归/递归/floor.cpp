/*#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
int a[35] = { 0 };
int n, sum = 0;
int main()
{
	int i;
	a[1] = 1;
	a[2] = 2;
	for (i = 3; i <= 32; i++)
	{
		a[i] = a[i - 1] + a[i - 2];
	}
	while (scanf("%d", &n)!=EOF)
	{
		printf("%d\n", a[n]);
	}
	while (1);
	return 0;
}*/