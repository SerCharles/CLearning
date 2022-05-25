#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char word[1100];
char ans[1100] = { 0 };
int hash[27] = { 0 };
int length, num = 0;
int main()
{
	gets(word);
	length = strlen(word);
	int i;
	for (i = 0; i < length; i++)
	{
		if (word[i] == ' ')
		{
			num++;
			ans[num] = word[i];
		}
		else
		{
			int ctoi = word[i] - 'a' + 1;
			hash[ctoi]++;
			if (hash[ctoi] == 1 || hash[ctoi] == 3 || hash[ctoi] == 6)
			{
				num++;
				ans[num] = word[i];
			}
		}
	}
	for (i = 1; i <= num; i++) printf("%c", ans[i]);
	return 0;
}