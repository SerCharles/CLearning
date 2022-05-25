#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
int sum=0, n,num=0;
int hash[100001] = { 0 };
int main()
{
	scanf("%d", &n);
	int i,j;
	hash[1] = 1;
	for (i = 2; i <= 330; i++)
	{
		if (hash[i] == 0)
		{
			j = 2;
			while (i*j <= 100000)
			{
				hash[i*j] = 1;
				j++;
			}
		}
	}
	i = 2;
	while (num< n)
	{
		if (hash[i] == 0)
		{
			num++;
			sum = sum + i;
		}
		i++;
	}
	printf("%d", sum);
	return 0;
}
