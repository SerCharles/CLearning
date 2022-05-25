#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
int m;
char n;
int main()
{
	scanf("%d", &m);
	if (m >= 90) n = 'A';
	else if (m >= 80) n = 'B';
	else if (m >= 70) n = 'C';
	else if (m >= 60) n = 'D';
	else n = 'F';
	printf("%c", n);
	return 0;
}