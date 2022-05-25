#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int judge(char w[]);
void change(char w[], int mod);
int main()
{
	char word[30] = { 0 };
	int mod = 0;
	scanf("%s", word);
	mod = judge(word);
	change(word,mod);
	printf("%s", word);
	return 0;
}
int judge(char w[])
{
	int length;
	length = strlen(w);
	char c1 = w[length - 1], c2 = w[length - 2];
	if (c1 == 's' || c1 == 'x' || c1 == 'z' || (c1 == 'h'&&c2 == 'c') || (c1 == 'h'&&c2 == 's')) return 1;
	else if (c1 == 'y'&&c2 != 'a'&&c2 != 'e'&&c2 != 'i'&&c2 != 'o'&&c2 != 'u') return 2;
	else return 3;
}
void change(char w[],int mod)
{
	int length;
	length = strlen(w);
	if (mod == 1)
	{
		w[length] = 'e';
		w[length + 1] = 's';
	}
	else if (mod == 2)
	{
		w[length - 1] = 'i';
		w[length] = 'e';
		w[length + 1] = 's';
	}
	else
	{
		w[length] = 's';
	}
}