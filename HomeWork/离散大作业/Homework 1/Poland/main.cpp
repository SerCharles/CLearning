//£¡>&>|>^>~
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char formula[10010];
char symbol[10] = { 0,'!','&','|' ,'^','~' };
int belong[10010] = { 0 }, visit[10010] = { 0 };
int num = 0;
struct swadia
{
	int h, t;
}piece[10010];
int length;
void swap(int position, int len)
{
	//swap the char at 'position' and the string before it whose length is 'len'
	char temp;
	int i;
	temp = formula[position];
	for (i = position - 1; i >= position - len; i--)
	{
		formula[i + 1] = formula[i];
	}
	formula[position - len] = temp;
}
void handle(int head, int tail)
{ //handle every stratas
	int i, j;
	for (i = 1; i <= 5; i++)
	{
		for (j = head; j <= tail; j++)
		{
			if (formula[j] == symbol[i] && belong[j] == 0)
			{
				if (i == 1)//handle !
				{
					int k = j, l;
					while (1)
					{
						if (formula[k + 1] != '!') break;
						k++;
					}
					if (formula[k + 1] == '(')
					{
						int a = belong[k + 2];
						piece[a].h = j;
						for (l = j; l <= k + 1; l++) belong[l] = a;
						int b = piece[a].t + 1;
						if (formula[b] == ')')
						{
							belong[b] = a;
							piece[a].t = b;
						}
					}
					else if (belong[k + 1] == 0)
					{
						num++;
						for (l = j; l <= k + 1; l++)
						{
							belong[l] = num;
						}
						piece[num].h = j;
						piece[num].t = k + 1;
					}
					else
					{
						int a = belong[k + 1];
						for (l = j; l <= k; i++) belong[l] = a;
						piece[a].h = j;
					}
				}
				else
				{
					//handle case left
					if (formula[j - 1] == ')')
					{
						int a = belong[j - 2];
						int b = piece[a].h - 1;
						if (formula[b] == '(')
						{
							belong[b] = a;
							piece[a].h = b;
						}
						belong[j - 1] = a;
						piece[a].t = j - 1;
						swap(j, piece[a].t - piece[a].h + 1);
						belong[j] = a;
						piece[a].t = j;
					}
					else if (belong[j - 1] == 0)
					{
						swap(j, 1);
						num++;
						belong[j] = num;
						belong[j - 1] = num;
						piece[num].h = j - 1;
						piece[num].t = j;
					}
					else
					{
						int a = belong[j - 1];
						swap(j, piece[a].t - piece[a].h + 1);
						belong[j] = a;
						piece[a].t = j;
					}
					//handle case right
					if (formula[j + 1] == '(')
					{
						int a = belong[j + 2];
						int b = piece[a].t + 1;
						int c = belong[j];
						int k;
						if (formula[b] == ')')
						{
							belong[b] = a;
							piece[a].t = b;
						}
						belong[j + 1] = a;
						piece[a].h = j + 1;
						piece[c].t = piece[a].t;
						for (k = piece[a].h; k <= piece[a].t; k++)
						{
							belong[k] = c;
						}
					}
					else if (belong[j + 1] == 0)
					{
						int a = belong[j];
						belong[j + 1] = a;
						piece[a].t = j + 1;
					}
					else
					{
						int a = belong[j];
						int b = belong[j + 1];
						int k;
						piece[a].t = piece[b].t;
						for (k = piece[b].h; k <= piece[b].t; k++)
						{
							belong[k] = a;
						}
					}
				}
			}
		}
	}
}
int find(int head, int tail)
{//get the '('and '(' to divide the formula into stratas
	int i, j;
	for (i = head; i <= tail; i++)
	{
		if (formula[i] == '('&&visit[i] == 0)
		{
			find(i + 1, tail);
		}
		if (formula[i] == ')'&&visit[i] == 0)
		{
			handle(head, i - 1);
			for (j = head - 1; j <= i; j++) visit[j] = 1;
			return 0;
		}
	}
	handle(head, tail);
	return 0;
}
int main()
{
	scanf("%s", formula);//input the formula and get its length
	length = strlen(formula);
	find(0, length - 1);
	int i;
	for (i = 0; i < length; i++)
	{
		if (formula[i] != '('&&formula[i] != ')') printf("%c", formula[i]);
	}
	while (1);
	return 0;
}