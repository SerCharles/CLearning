#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int blank = 0, enter = 0, els = 0;
char c;

int main()
{
	while(1)
	{ 
		scanf("%c", &c);
		if (c == ' ') blank++;
		else if (c == '\n')enter++;
		else if (c == '#') break;
		else els++;
	}
	printf("%d %d %d", blank, enter, els);
	return 0;
}