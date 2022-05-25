#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char formula[110];
struct number
{
	int num, head, tail;
	bool p;
}list[110];
int length,ans=0;
int getnum();
int turnnum(int flag);
int main()
{
	scanf("%s", formula);
	length = strlen(formula);
	ans=getnum();
	printf("%d", ans);
	return 0;
}
int getnum()
{
	int sum = 0,i,h=0,t=0;
	for(i=0;i<length;i++)
	{
		list[1].p = 1;
		if (formula[i] == '+' || formula[i] == '-'||formula[i]=='=')
		{
			t = i - 1;
			sum++;
			list[sum].head = h; list[sum].tail = t;
			list[sum].num=turnnum(sum);
			h = i + 1;
			if (formula[i] == '+')
			{
				list[sum + 1].p = 1;
			}
			else if (formula[i] == '-')
			{
				list[sum + 1].p = 0;
			}
			if (list[sum].p == 1) ans = ans + list[sum].num;
			else ans = ans - list[sum].num;
			if (formula[i] == '=') return ans;
		}
	}
	return ans;
}
int turnnum(int flag)
{
	int h = list[flag].head, t = list[flag].tail;
	int i,time=1,n=0;
	for (i = t; i >= h; i--)
	{
		n = n + (formula[i]-48) * time;
		time = time * 10;
	}
	return n;
}
