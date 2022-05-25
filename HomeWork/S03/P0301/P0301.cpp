#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
int ans = 0, max, min;
int main()
{
	scanf("%d%d", &min, &max);
	int i;
	for (i = min; i <= max; i++)
	{
		ans = ans + i*i;
	}
	printf("%d", ans);
	return 0;
}