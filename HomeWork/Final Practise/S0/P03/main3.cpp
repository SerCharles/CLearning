#define _CRT_NONSTDC_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define maxn 100
int n,m;
char word[110]={0};
char pass[110]={0};
char originalpass[110]={0};
char l[110]={0};
char ans[110]={0};
void turn(int times)
{
	char temp[110]={0};
	int i,t;
	for(i=1;i<=n;i++)
	{
		t=(i+n*1000-times)%n;
		if(t==0) t=n;
    temp[t]=pass[i];
	}
	for(i=1;i<=n;i++) pass[i]=temp[i];
}
int main()
{
    scanf("%d%d",&n,&m);
	fflush(stdin);
	int i;
	for(i=1;i<=n;i++)
	{
	scanf("%c",&word[i]);
	}
	fflush(stdin);
	for(i=1;i<=n;i++)
	{
		scanf("%c",&pass[i]);
		originalpass[i]=pass[i];
	}
	for(i=1;i<=m;i++)
	{
		char type,tt;
		int p=0,q=0,length=0,j,ii;
		for(j=1;j<=n;j++) pass[j]=originalpass[j];
		{
		fflush(stdin);
		scanf("%c",&type);
		scanf("%d%d",&p,&q);
		while(1)
		{
          scanf("%c",&tt);
		  if(tt=='\n'||tt==EOF) break;
		  l[length]=tt;
		  length++;
		}
		length-=1;
		}
		turn(p);
		for(ii=1;ii<=length;ii++)
		{
			if(type=='E')
			{
				int place=0;
		 	 for(j=1;j<=n;j++)
			 {
              if(word[j]==l[ii]) 
			  {
				  place=j;
				  break;
			  }
			 }
			 ans[ii]=pass[place];
			 turn(q);
			}
			if(type=='D')
			{
				int place=0;
				for(j=1;j<=n;j++)
				{
					if(pass[j]==l[ii]) 
					{
						place=j;
						break;
					}
				}
				ans[ii]=word[place];
				turn(q);
			}
			
		}
		for(ii=1;ii<=length;ii++) 
			{
				printf("%c",ans[ii]);
				ans[ii]=0;
		    }
		printf("\n");
	}
	return 0;
}