#define _CRT_NONSTDC_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int min,max,ans=0;

int main()
{
	scanf("%d%d",&min,&max);
	int i;
	for(i=1;i<=1000;i++)
	{
		if(i*i*i>=min&&i*i*i<=max) ans++;
	}
	printf("%d",ans);
	return 0;
}