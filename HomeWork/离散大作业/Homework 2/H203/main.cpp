//！>&>|>^>~
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char formula[110];//input formula
int length = 0;//length of input formula
char symbol[10] = { 0,'!','&','|' ,'^','~' };
int belong[110] = { 0 }, visit[110] = { 0 };
int queue[60] = { 0 };//the position of the elements in var
char var[20];//the elements of the formula,in ASCII orders
int valueofvar[20][50000] = { 0 }; //diagram
int num = 0, sumofvar = 0,situation=1; 
int lengthofor = 0, lengthofand = 0;//length of formula answers
int timeofor = 0, timeofand = 0;//number formulas in the answer
char formulaofor[50000] = { 0 }, formulaofand[50000] = { 0 };//formula answer
int answerofor[50000] = { 0 }, answerofand[50000] = { 0 }; //formula answer by numbers
struct swadia
{
	int h, t, value;
}piece[10010];
int indexof2(int times)
{
	int i,v=1;
	for (i = 1; i<=times; i++)
	{
		v = v * 2;
	}
	return v;
}
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
}
void handle(int head, int tail)
{ //handle every stratas and get the diagram
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
							piece[num].value = calculate(1, valueofvar[c][situation], 0);
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
						valueleft = valueofvar[c][situation];
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
						valueright = valueofvar[c][situation];
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
		for (j = situation; j < situation + indexof2(sumofvar - sequence);j++)
		{
			valueofvar[sequence][j] = i;
		}
		if (sequence == sumofvar)
		{
			find(0, length - 1);
			for (j = 1; j <= num; j++)
			{
				if (piece[j].value >= 0) valueofvar[sequence+1][situation]=piece[j].value;
			}
			memset(belong, 0, sizeof(belong));
			memset(piece, 0, sizeof(piece));
			memset(visit, 0, sizeof(visit));
			num = 0;
			situation++;
		}
		else
		{
			init(sequence + 1);
		}
	}
}
void getsequence(int place,int value,int type)//get the formula of number
{
	if (type == 0)
	{
		answerofor[timeofor] += indexof2(sumofvar - place)*value;
	}
	if (type == 1)
	{
		answerofand[timeofand] += indexof2(sumofvar - place)*value;
	}
}
void handlediagram()
{
	int i, j;
	situation--;
	for (i = 1; i <= situation; i++)
	{
		if (valueofvar[sumofvar+1][i] == 1)//主析取范式
		{
			timeofor++;
			if (lengthofor)
			{
				lengthofor++;
				formulaofor[lengthofor] = '|';
			}
			lengthofor++;
			formulaofor[lengthofor] = '(';
			for (j = 1; j <=sumofvar ; j++)
			{
				if (j>1)
				{
					lengthofor++;
					formulaofor[lengthofor] = '&';
				}
				if (valueofvar[j][i] == 1)
				{
					lengthofor++;
					formulaofor[lengthofor] = var[j];
					getsequence(j, 1,0);
				}
				else
				{
					lengthofor = lengthofor+ 2;
					formulaofor[lengthofor - 1] = '!';
					formulaofor[lengthofor] = var[j];
					getsequence(j, 0,0);
				}
			}
			lengthofor++;
			formulaofor[lengthofor] = ')';
		}
	}
	for (i = situation; i >= 1; i--)//主合取范式
	{
		if (valueofvar[sumofvar+1][i] == 0)
		{
			timeofand++;
			if (lengthofand)
			{
				lengthofand++;
				formulaofand[lengthofand] = '&';
			}
			lengthofand++;
			formulaofand[lengthofand] = '(';
			for (j = 1; j <=sumofvar; j++)
			{
				if (j>1)
				{
					lengthofand++;
					formulaofand[lengthofand] = '|';
				}
				if (valueofvar[j][i] == 0)
				{
					lengthofand++;
					formulaofand[lengthofand] = var[j];
					getsequence(j, 1, 1);
				}
				else
				{
					lengthofand = lengthofand + 2;
					formulaofand[lengthofand - 1] = '!';
					formulaofand[lengthofand] = var[j];
					getsequence(j, 0, 1);
				}
			}
			lengthofand++;
			formulaofand[lengthofand] = ')';
		}
	}
}
void output()
{
	int i;
	if (2<=lengthofor &&lengthofor<= 7)
	{
		for (i = 2; i < lengthofor; i++) printf("%c", formulaofor[i]);
	}
	else if(lengthofor>7)
	{
		for (i = 1; i <= lengthofor; i++) printf("%c", formulaofor[i]);
	}
	else
	{
		printf("Empty Formula");
	}
	printf("\n");
	if (timeofor == 0)
	{
		printf("Empty Formula");
	}
	else
	{
		printf("|");
		for (i = 1; i < timeofor; i++)
		{
			printf("%d,", answerofor[i]);
		}
		printf("%d", answerofor[timeofor]);
	}
	printf("\n");
	if (2 <= lengthofand&&lengthofand <= 7)
	{
		for (i = 2; i < lengthofand; i++) printf("%c", formulaofand[i]);
	}
	else if (lengthofand>7)
	{
		for (i = 1; i <= lengthofand; i++) printf("%c", formulaofand[i]);
	}
	else
	{
		printf("Empty Formula");
	}
	printf("\n");
	if (timeofand == 0)
	{
		printf("Empty Formula");
	}
	else
	{
		printf("&");
		for (i = 1; i < timeofand; i++)
		{
			printf("%d,", answerofand[i]);
		}
		printf("%d", answerofand[timeofand]);
	}
}
int main()
{
	scanf("%s", formula);//input the formula and get its length
	length = strlen(formula);
	getelement();//get the element of the formula
	init(1); //get the diagram
	handlediagram(); //get the answers
	output();//print the answers
	return 0;
}