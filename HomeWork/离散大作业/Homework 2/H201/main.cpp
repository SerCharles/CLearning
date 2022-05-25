//£¡>&>|>^>~
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char formula[10010];
char symbol[10] = { 0,'!','&','|' ,'^','~' };
int belong[10010] = { 0 }, visit[10010] = { 0 };
int queue[60] = { 0 };//the position of the elements in var
char var[60];//the elements of the formula,in ASCII orders
int valueofvar[60] = { 0 };
int num = 0, sumofvar = 0;
struct swadia
{
	int h, t, value;
}piece[10010];
int length;
int calculate(int method, int left, int right)
{
	if (method == 1) return !left;
	if (method == 2) return left&right;
	if (method == 3) return left | right;
	if (method == 4)
	{
		if (left == 1 && right == 0) return 0;
		else return 1;
	}
	if (method == 5)
	{
		if (left == right) return 1;
		else return 0;
	}
}
void getelement()
{
	int i;
	for (i = 0; i < length; i++)//get the elements of the formula
	{
		if ((formula[i] >= 65 && formula[i] <= 90) || (formula[i] >= 97 && formula[i] <= 122))
		{
			queue[formula[i]] = 1;
		}
	}
	for (i = 65; i <= 122; i++)
	{
		if (queue[i] == 1)
		{
			sumofvar++;
			var[sumofvar] = i;
			queue[i] = sumofvar;
		}
	}
	for (i = 1; i <= sumofvar; i++)
	{
		printf("%c  ", var[i]);
	}
	printf("RS\n");
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
						if ((k - j + 1) % 2 == 1)
						{
							piece[a].value = calculate(1, piece[a].value, 0);
						}
					}
					else if (belong[k + 1] == 0)
					{
						num++;
						for (l = j; l <= k + 1; l++)
						{
							belong[l] = num;
						}
						int c = queue[formula[k + 1]];
						piece[num].h = j;
						piece[num].t = k + 1;
						if ((k - j + 1) % 2 == 1)
						{
							piece[num].value = calculate(1, valueofvar[c], 0);
						}
					}
					else
					{
						int a = belong[k + 1];
						for (l = j; l <= k; i++) belong[l] = a;
						piece[a].h = j;
						if ((k - j + 1) % 2 == 1)
						{
							piece[a].value = calculate(1, piece[a].value, 0);
						}
					}
				}
				else
				{
					//handle case left
					int valueleft, valueright;
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
						belong[j] = a;
						piece[a].t = j;
						valueleft = piece[a].value;
					}
					else if (belong[j - 1] == 0)
					{
						int c = queue[formula[j - 1]];
						valueleft = valueofvar[c];
						num++;
						belong[j] = num;
						belong[j - 1] = num;
						piece[num].h = j - 1;
						piece[num].t = j;
						piece[num].value = valueleft;
					}
					else
					{
						int a = belong[j - 1];
						belong[j] = a;
						piece[a].t = j;
						valueleft = piece[a].value;
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
						valueright = piece[a].value;
						piece[a].h = j + 1;
						piece[c].t = piece[a].t;
						for (k = piece[a].h; k <= piece[a].t; k++)
						{
							belong[k] = c;
						}
						piece[c].value = calculate(i, valueleft, valueright);
						piece[a].value = -1;
					}
					else if (belong[j + 1] == 0)
					{
						int c = queue[formula[j + 1]];
						valueright = valueofvar[c];
						int a = belong[j];
						belong[j + 1] = a;
						piece[a].t = j + 1;
						piece[a].value = calculate(i, valueleft, valueright);
					}
					else
					{
						int a = belong[j];
						int b = belong[j + 1];
						valueright = piece[b].value;
						int k;
						piece[a].t = piece[b].t;
						for (k = piece[b].h; k <= piece[b].t; k++)
						{
							belong[k] = a;
						}
						piece[a].value = calculate(i, valueleft, valueright);
						piece[b].value = -1;
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
void init(int sequence)
{
	int i, j;
	for (i = 0; i <= 1; i++)
	{
		valueofvar[sequence] = i;
		if (sequence == sumofvar)
		{
			find(0, length - 1);
			for (j = 1; j <= sumofvar; j++)
			{
				printf("%d  ", valueofvar[j]);
			}
			for (j = 1; j <= num; j++)
			{
				if (piece[j].value >= 0) printf("%d", piece[j].value);
			}
			printf("\n");
			memset(belong, 0, sizeof(belong));
			memset(piece, 0, sizeof(piece));
			memset(visit, 0, sizeof(visit));
			num = 0;
		}
		else
		{
			init(sequence + 1);
		}
	}


}
int main()
{
	int i;
	scanf("%s", formula);//input the formula and get its length
	length = strlen(formula);
	getelement();//get the element of the formula
	init(1);
	return 0;
}