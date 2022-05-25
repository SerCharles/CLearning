#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char ch;
int current = 1;
int visit[3][27] = { 0 };
int judge()
{
	int i;
	for (i = 1; i <= 26; i++)
	{
		if (visit[1][i] != visit[2][i]) return 0;
	}
	return 1;
}
int main()
{
	while (1)
	{
		scanf("%c", &ch);
		if (ch == '\0' || ch == '\n')
		{
			break;
		}
			if (ch >= 'A'&&ch <= 'Z')
			{
				visit[current][ch - 'A']++;
			}
			else if (ch >= 'a'&&ch <= 'z')
			{
				visit[current][ch - 'a']++;
			}
			else if (ch == ' ')
			{
				current=2;
			}
		}
if (judge()) printf("yes");
else printf("no");
return 0;
}


