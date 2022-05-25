#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
long long int n;
long long int ans = 0;
int main()
{
	scanf("%lld", &n);
	int i;
	for (i = 2; i <= sqrt(n); i++)
	{
		if (n%i == 0)
		{
			ans = n / i;
			break;
		}
	}
	printf("%lld", ans);
	return 0;
}