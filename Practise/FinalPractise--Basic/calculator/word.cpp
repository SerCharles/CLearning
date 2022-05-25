#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
char word[10];
int length_word = 0,length_text=0,time=0;
int whether = 0, place = 0,ans=0;
char text[1000000];
int flag[1000000] = { 0 }, head[1000000] = { 0 };
int compare(int l);
int main()
{
	scanf("%s", word);
	length_word = strlen(word);
	int i = 0; char a;
	for (i = 0; i < length_word; i++)
	{
		if (word[i] <= 'Z'&&word[i]>='A') word[i] = word[i] - 'A' + 'a';
	}
	int w = 0;
	while (1)
	{
		
		a = getchar();
		if (length_text!= 0 && a == '\n') break;
		if (a <= 'Z'&&a >= 'A') a = a - 'A' + 'a';
		if (a != '\n')
		{
			length_text++;
			text[length_text - 1] = a;
		}
		if (a >= 'a'&&a <= 'z'&&w == 0)
		{
			time++;
			w = 1;
			head[time] = length_text - 1;
		}
		if (a == ' '&&w==1)
		{
			w = 0;
			flag[time] = length_text - 2;
		}
	}
	flag[time] = length_text-1;
	for (i = 1; i <= time; i++)
	{
		if (flag[i] - head[i]+1 == length_word)
		{
			if (compare(head[i]))
			{
				if (whether == 0)
				{
					whether = 1;
					place = head[i];
				}
				ans++;
			}
		}
	}
	if (whether == 1)
	{
		printf("%d %d", ans, place);
	}
	else printf("%d", -1);
	return 0;
}
int compare(int l)
{
	int i;
	for (i = 0; i < length_word; i++)
	{
		if (word[i] != text[i + l]) return 0;
	}
	return 1;
}