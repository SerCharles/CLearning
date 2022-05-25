#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n,flag=0,max=0;
int a[22];
struct swadia
{
	int num, visit;
}list[22];
int main()
{
	scanf("%d", &n);
	int i;
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		if (i == 1)
		{
			flag++;
			list[flag].num = a[i];
			list[flag].visit = 1;
		}
		else
		{
			if (a[i] != a[i - 1])
			{
				flag++;
				list[flag].num = a[i];
				list[flag].visit = 1;
			}
			else
			{
				list[flag].visit++;
			}
		}
	}
	for (i = 1; i <= flag; i++)
	{
		if (list[i].visit > list[max].visit)
		{
			max = i;
		}
	}
	printf("%d", list[max].num);
	return 0;
}