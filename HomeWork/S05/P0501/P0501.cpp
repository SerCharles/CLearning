#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int length;
char ch[1];
char str[22];
int main()
{
	scanf("%s", str);
	scanf("%s", ch);
	length = strlen(str);
	int i;
	for (i = 0; i < length; i++)
	{
		if (str[i] != ch[0])
		{
		  printf("%c", str[i]);
	    }
	}
	return 0;
}
