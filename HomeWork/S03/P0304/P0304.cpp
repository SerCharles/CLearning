#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
int n;
double answer=0;
double mother = 1.00, son = 2.00;
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		answer = answer + son / mother;
		int temp = son + mother;
		mother = son; son = temp;
	}
	printf("%.2f", answer);
	return 0;
}
