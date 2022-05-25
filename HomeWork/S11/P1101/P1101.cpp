#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
FILE *fin = NULL;
struct Node
{
	int num;
	char name[30];
	int score;
	Node* next;
};
Node* build();
Node* Sort(Node* head);
void print(Node* head);
void swap(Node* the, Node* flag);
int length = 0;
int main()
{
	fin = fopen("data1.txt","r");
	Node* head;
	head = build();
	head = Sort(head);
	print(head);
	fclose(fin);
	return 0;
}
Node* build()
{
	Node* head = NULL, *previous = NULL, *the = NULL;
	while (!feof(fin))
	{
			length++;
			the = (Node*)malloc(sizeof(Node));
			fscanf(fin,"%d%s%d",&the->num, the->name, &the->score);
			if (head == NULL)
			{
				head = the;
				previous = the;
			}
			else
			{
				previous->next = the;
				previous = the;
			}
	}
	previous->next = NULL;
	return head;
}
Node* Sort(Node* head)
{
	Node*previous = head, *the = head,*flag=the->next;
	if (the == NULL) return head;
	if (head->next == NULL) return head;
	int i, j;
	while (the->next!=NULL)
	{
		flag = the->next;
		while (flag!=NULL)
		{
			if (the->score > flag->score) swap(the, flag);
			flag = flag->next;
		}
		previous = the;
		the = the->next;
	}
	return head;
}
void print(Node* head)
{
	Node*previous = head, *the = head;
	while (the != NULL)
	{
		printf("%d %s %d\n", the->num, the -> name, the->score);
		previous = the;
		the = the->next;
	}
}
void swap(Node* the, Node* flag)
{
	int tempn, temps;
	char tempname[30];
	tempn = the->num; temps = the->score;
	strcpy(tempname, the->name);
	the->num = flag->num; the->score = flag->score;
	strcpy(the->name, flag->name);
	flag->num = tempn; flag->score = temps;
	strcpy(flag->name, tempname);
}