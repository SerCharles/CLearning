#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int a[110] = { 0 }, b[110] = { 0 }, answer[110] = { 0 };
int length1=0, length2=0,end,t;
char c[110],d[110];
int main()
{
	int i;
	scanf("%s", c);
	length1 = strlen(c);
	for(i=1;i<=length1;i++)
	{
		a[i] = c[i - 1] - 48;
	}
	scanf("%s", d);
	length2 = strlen(d);
	for (i = 1; i <= length2; i++)
	{
	 b[i] = d[i - 1] - 48;
	}	
	
	if (length1 >= length2)
	{
		for (i = 1; i <= length1; i++)
		{
			if (i <= length2)
			{
				int temp;
				temp = answer[i] + a[length1 + 1 - i] + b[length2 + 1 - i];
				answer[i] = temp % 10;
				answer[i + 1] = answer[i + 1] + temp / 10;
			}

			else
			{
				int temp;
				temp = answer[i] + a[length1 + 1 - i];
				answer[i] = temp % 10;
				answer[i + 1] = answer[i + 1] + temp / 10;
			}
		}
	}
		else
	{
			for (i = 1; i <= length2; i++)
		{
			if (i <= length1)
			{
				int temp;
				temp = answer[i] + a[length1 + 1 - i] + b[length2 + 1 - i];
				answer[i] = temp % 10;
				answer[i + 1] = answer[i + 1] + temp / 10;
			}
			else
			{
				int temp;
				temp = answer[i] + a[length2 + 1 - i];
				answer[i] = temp % 10;
				answer[i + 1] = answer[i + 1] + temp / 10;
			}
		}
	}
	if (length1 > length2) t = length1;
	else t = length2;
	if (answer[t + 1]) end = t + 1;
	else end = t;
	for (i = end; i >= 1; i--)
	{
		printf("%d", answer[i]);
	}
	while (1);
	return 0;
}