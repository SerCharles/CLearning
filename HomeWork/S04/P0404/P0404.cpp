#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
int year;
int month[15] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
int answer[15] = { 0 };
int day = 365,week = 5;
int judge(int y)
{
	if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) return 1;
	else return 0;
}
int main()
{
	int i;
	scanf("%d", &year);
	if (year >= 2012)
	{
		for (i = 2012; i < year; i++)
		{
			if (judge(i)) day = 366;
			else day = 365;
			week = (week + day) % 7;
		}
	}
	else
	{
		for (i = 2011; i >= year; i--)
		{
			if (judge(i)) day = 366;
			else day = 365;
			week = (week - day) % 7;
		}
	}
	 answer[1] = week;
	 if(judge(year)) month[2] = 29; 
	 for (i = 1; i <= 12; i++)
	 {
		 if (answer[i] == 5)
		 {
			 if (i <= 9) printf("%d-0%d-13\n",year,i);
			 else printf("%d-%d-13\n", year, i);
		 }
		 answer[i+1] = (answer[i] + month[i ]) % 7;
	 }
	 return 0;
}