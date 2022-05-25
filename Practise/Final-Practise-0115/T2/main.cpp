#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
char formula[1300000] = { 0 };
int length;
int num[100100] = { 0 };
int sum = 0,ans=0;
int get_num(int head, int tail);
int get(int head, int tail);
int main()
{
	scanf("%s", formula);
	length = strlen(formula);
	formula[length] = '+';
	int i,flag_last=0,flag=0;
	for (i = 0; i <= length; i++)
	{
		if (formula[i] == '+')
		{
			flag = i - 1;
			sum++;
			num[sum]=get_num(flag_last, flag);
			flag_last = i + 1;
		}
	}
	for(i=1;i<=sum;i++)
	{
		ans = ans + num[i];
		ans = ans % 10000;
	}
	printf("%d", ans);
	return 0;
}
int get_num(int head, int tail)
{
	int result = 1;
	int i, nm = 0,flag_last=head,flag=head;
	for (i = head; i <= tail+1; i++)
	{
		if (formula[i] == '*'||i==tail+1)
		{
			flag = i - 1;
			nm = get(flag_last, flag)%10000;
			result = (result*nm) % 10000;
			flag_last = i + 1;
		}
	}
	return result;
}
int get(int head, int tail)
{
	int i, nm = 0,multi=1;
	for (i = tail; i >= head; i--)
	{
		nm = nm + (formula[i] - '0')*multi;
		multi = multi * 10;
	}
	return nm;
}