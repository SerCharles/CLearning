#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>
char big, small;
int main()
{
	scanf("%c", &big);
	small = big + 32;
	printf("%c", small);
	return 0;
}