/*#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int a,sum=0,n;
int answer[20] = { 0 };
char c;
void handle(int number)
{
	sum++;
	answer[sum] = number % n;
	if (number / n)
	{
		handle(number / n);
	}
}
int main()
{
	scanf_s("%d%d", &a,&n);
	handle(a);
	int i;
	for (i = sum; i >= 1; i--)
	{
		if (answer[i] < 10)
		{
			c = answer[i]+'0';
		}
		else
		{
			c = 'A' - 10 + answer[i];
		}
		printf("%c", c);
	}
	while (1);
	return 0;
}*/