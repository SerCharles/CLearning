#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char num[6];
int length = 0;
int main()
{
	scanf("%s", num);
	length = strlen(num);
	int i;
	for (i = length - 1; i >= 0; i--)
	{
		printf("%c", num[i]);
	}
	return 0;
}