#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int num, sum = 0;
char pass1[110], note1[110], pass2[110],note2[110];
int length1, length2;
int chart[30] = { 0 }, hash[30] = { 0 };//chart:每个字母对应的密文 hash：这个密文是否被使用过
int handle()
{
	int i;
	for (i = 0; i <length1; i++)
	{
		int a, b;
		a = pass1[i] - 64;
		b = note1[i] - 64;
		if (chart[a] == 0)
		{
			chart[a] = b;
		}
		else if(chart[a]!=b)
		{
			return 0;
		}
	}
	for (i = 1; i <= 26; i++)
	{
		if (chart[i] == 0)
		{
			return 0;
		}
		else if (hash[chart[i]] == 1)
		{
			return 0;
		}
		hash[chart[i]] = 1;
	}
	return 1;
}
int main()
{

	scanf("%s",&pass1);
	scanf("%s",&note1);
	length1 = strlen(pass1);
	if (handle())
	{
		scanf("%s", &pass2);
		length2 = strlen(pass2);
		int i;
		for (i = 0; i < length2; i++)
		{
			note2[i] = chart[pass2[i] - 64] + 64;
		}
		printf("%s", note2);
	}
	else
	{
		printf("Failed");
	}
	while (1);
	return 0;
}