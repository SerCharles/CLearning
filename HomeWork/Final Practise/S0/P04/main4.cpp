#define _CRT_NONSTDC_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdio.h>
int n,m;
struct Node
{
	char date[20],name[110];
	int num;
	Node* next;
};
Node* build(int sum);
void print(Node* head);
Node* remove(int h,int t,Node* head);
Node* sort(Node* head, int prior1,int prior2,int prior3,int type1,int type2,int type3);
int	compare(Node* the,Node* flag,int prior1,int prior2,int prior3,int type1,int type2,int type3);
void swap(Node* a1,Node* a2);
int main()
{
	Node* head;
	scanf("%d",&n);
	head=build(n);
	scanf("%d",&m);
	int i;
	char order,type[3]={0},a;int h,t;
	int pr[3]={0},tp[3]={0};
	for(i=1;i<=m;i++)
	{
		fflush(stdin);
		while (1)
		{
			 a = getchar();
			if (a == 'S' || a == 'D') break;
		}
		order=a;
		if(order=='S')
		{
			scanf("%s",type);
			int k;
			for(k=0;k<=2;k++)
			{
				if(type[k]==0) break;
				if(type[k]=='t') 
					{
						tp[k]=0;
						pr[k]=1;
				    }
				if(type[k]=='T') 
				{
					tp[k]=1;
					pr[k]=1;
				}
				if(type[k]=='l') 
				{
					tp[k]=0;
					pr[k]=2;
				}
				if(type[k]=='L') 
				{
					tp[k]=1;
					pr[k]=2;
				}
				if(type[k]=='v') 
				{
					tp[k]=0;
					pr[k]=3;
				}
				if(type[k]=='V') 
				{
					tp[k]=1;
					pr[k]=3;
				}
				 
			}
			sort(head, pr[0], pr[1], pr[2], tp[0], tp[1], tp[2]);
		}
		if(order=='D')
		{
			scanf("%d%d",&h,&t);
			head=remove(h,t,head);
		}
	}
	print(head);
	return 0;
}
Node* build(int sum)
{
	int i;
	Node* head=NULL;Node* the=NULL;Node* previous=NULL;
	for(i=1;i<=n;i++)
	{
		the=(Node*)malloc(sizeof(Node));
		scanf("%s",the->date);
		scanf("%s",the->name);
		scanf("%d",&the->num);
		if(head==NULL)
		{
			previous=the;
			head=the;
		}
		else
		{
			previous->next=the;
			previous=the;
		}
	}
	previous->next=NULL;
	return head;
}
void print(Node* head)
{
	Node* the=head;Node* previous=head;
	while(the!=NULL)
	{
		printf("%s %s %d\n",the->date,the->name,the->num);
		previous=the;
		the=the->next;
		free(previous);
	}
}
Node* remove(int h,int t,Node* head)
{
	Node* the=head;Node* previous=head;Node* lineh=NULL;Node* linet=NULL;Node* todelete=NULL;
	int flag=1;
	while(the!=NULL)
	{
		if(flag==h-1)
		{
			lineh=the;
		}
		if(flag>=h&&flag<=t)
		{
			todelete=the; 
		}
		if(flag==t+1)
		{
			linet=the;
		}
		the=the->next;
		  if(flag==h-1) lineh->next=NULL;
		 if(todelete!=NULL)
		 {
		  free(todelete);
		  todelete=NULL;
		 }
		flag++;
	}
	if(lineh==NULL&&linet==NULL) return NULL;
	else if(lineh==NULL) head=linet;
	else if(linet==NULL) lineh->next=NULL;
	else lineh->next=linet;
	return head;
}
Node* sort(Node* head, int prior1,int prior2,int prior3,int type1,int type2,int type3)
{
	Node* the=head;Node* previous=head;Node* flag=the->next;
	if(head==NULL) return NULL;
	while(the->next!=NULL)
	{
		flag=the->next;
		while(flag!=NULL)
		{
			if(compare(the,flag,prior1,prior2,prior3,type1,type2,type3)) swap(the,flag);
			flag=flag->next;
		}
		previous=the;
		the=the->next;
	}
   return head;
}
void swap(Node* a1,Node* a2)
{
	char tempdate[20],tempname[110];int temp;
	strcpy(tempdate,a1->date); strcpy(tempname,a1->name);temp=a1->num;
	strcpy(a1->date,a2->date);strcpy(a1->name,a2->name);a1->num=a2->num;
	strcpy(a2->date,tempdate);strcpy(a2->name,tempname);a2->num=temp;
}
int	compare(Node* the,Node* flag,int prior1,int prior2,int prior3,int type1,int type2,int type3)
{
   int pr[4]={0};pr[1]=prior1;pr[2]=prior2;pr[3]=prior3;
   int tp[4]={0};tp[1]=type1;tp[2]=type2;tp[3]=type3;
   int i;
   for(i=1;i<=3;i++)
   {
	   if(pr[i]==0) break;
	   int k=0;
	   if(pr[i]==1)
	   {
		    k=strcmp(the->date,flag->date);
	   }
	   if(pr[i]==2)
	   {
		   k=strcmp(the->name,flag->name);
	   }
	   if(pr[i]==3)
	   {
		   if(the->num>flag->num) k=1;
		   if(the->num==flag->num) k=0;
		   if(the->num<flag->num) k=-1;
	   }
	   if(k>0)
	   {
		   if(tp[i]==1) return 0;
		   if(tp[i]==0) return 1;
	   }
	   else if(k<0)
	   {
		   if(tp[i]==1) return 1;
		   if(tp[i]==0) return 0;
	   }
   }
   return 0;
}