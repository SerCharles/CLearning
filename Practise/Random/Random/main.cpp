#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int x,input;
int hash[15] = { 0 };
char ans[7] = { 0 };
int inputlist[6] = { 0 }, randlist[6] = { 0 };
int judge()
{
	int i,j;
	for (i = 1; i <= 3; i++)
		for(j=0;j<i;j++)
	{
			if (randlist[i] == randlist[j]) return 0;
	}
	return 1;
}
void divide(int num, int list[])
{
	list[1] = num / 1000;
	num = num - list[1] * 1000;
	list[2] = num / 100;
	num = num - list[2] * 100;
	list[3] = num / 10;
	list[4] = num % 10;
}
/*�������
1��������̣���ȷ���¼�
2��α�����������������������ȷ�����̣�ͳ�������������)
�����������1:stdlib 2:srand�������� 3��rand�������� 0-32767�������
�ȣ�srand((unsigned)time(NULL));
����rand
	  */
int main()
{
	int i;
	srand((unsigned)time(NULL));
	while (1)
	{
		x = rand();
		x = x %9000;
		x = x + 1000;
		divide(x, randlist);
		if (judge())
		{
			break;
		}
	}
	for (i = 1; i <= 4; i++)
	{
		hash[randlist[i]] = 1;
	}
	i = 0;
	while(1)
	{
		i++;
		printf("Please input a number");
		printf("\n");
		scanf_s("%d", &input);
		divide(input, inputlist);
		int j;
		for (j = 1; j <= 4; j++)
		{
			if (inputlist[j] == randlist[j]) ans[j-1] = 'A';
			else if (hash[inputlist[j]] == 1) ans[j-1] = 'B';
			else ans[j - 1] = inputlist[j] + 48;
		}
		if (ans[0] == 'A'&&ans[1] == 'A'&&ans[2] == 'A'&&ans[3] == 'A')
		{
			printf("Right,Excited!");
			break;
		}
		if (i == 10)
		{
			printf("�㰡��Naive");
			break;
		}
		for (j = 0; j <= 3; j++)
		{
			printf("%c", ans[j]);
		}
		printf("\n")
			;
	}
	while (1);
	return 0;
}