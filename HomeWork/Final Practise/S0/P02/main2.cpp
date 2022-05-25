#define _CRT_NONSTDC_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int init,grow,bear,t,n;
long long int ans=0;
long long int rabbit[40]={0};
long long int newborn[40]={0};
int main()
{
	scanf("%d%d%d%d%d",&init,&grow,&bear,&t,&n);
	int i,j,total=1,former=1;
	int canbear=grow+1;
	int endbear=grow+t;
	int death=grow+t+1;
	 rabbit[1]=1;
	 newborn[1]=1;
	for(i=2;i<=n;i++)
	{
		 rabbit[i]=rabbit[i-1];
		  for(j=1;j<=t;j++)
		  {
			  if(i-j-grow>=1) newborn[i]+=newborn[i-j-grow]*bear;
		  }
		  rabbit[i]+=newborn[i];
		  if(i-t-grow-1>=1) rabbit[i]-=newborn[i-t-grow-1];
	}
	ans=rabbit[n];
	printf("%lld",ans*init);
	return 0;
}