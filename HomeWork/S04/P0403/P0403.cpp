#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
unsigned int n;
unsigned int handle()
{
	unsigned int sum = 1;
	while (n)
	{
		if (n % 10 != 0)  sum = sum*(n % 10);
		n = n / 10;
	}
	return sum;
}
int main()
{
	scanf("%ud", &n);
	while (n >= 10)
	{
		n=handle();
	}
	printf("%d", n);
	return 0;
}