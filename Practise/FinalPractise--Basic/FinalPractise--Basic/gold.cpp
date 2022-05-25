#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int n;
long long int sum = 0;
int main()
{
	scanf("%d", &n);
	int i,day=1,daycurrent=0;
	for (i = 1; i <= n; i++)
	{
		if (daycurrent >= day)
		{
			day++; daycurrent = 0;
		}
		sum += day;
		daycurrent++;
	}
	printf("%lld", sum);
	return 0;
}