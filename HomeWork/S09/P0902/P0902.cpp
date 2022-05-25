#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Swadia
{
	int num;
	Swadia* next;
};
int n1, n2;
Swadia* build(int num);
Swadia* insert(Swadia* head, int num);
void print(Swadia* head);
int judge(Swadia* head,int num);
int main()
{
	Swadia* head; int s; Swadia* ans = NULL;
	scanf("%d", &n1);
	head = build(n1);
	scanf("%d", &n2);
	for (int i = 1; i <= n2; i++)
	{
		scanf("%d", &s);
		if (judge(head, s))
		{
			ans = insert(ans, s);
		}
	}
	print(ans);
	return 0;
}
Swadia* build(int num)
{
	Swadia*head = NULL; Swadia* present = NULL; Swadia* previous = NULL;
	for (int i = 1; i <= num; i++)
	{
		present = (Swadia*)malloc(sizeof(Swadia));
		scanf("%d", &present->num);
		if (i == 1)
		{
			head = present;
			previous = head;
		}
		else
		{
			previous->next = present;
			previous = present;
		}
	}
	previous->next = NULL;
	return head;
}
void print(Swadia* head)
{
	Swadia* present = head; Swadia* previous = head;
	while (present != NULL)
	{
		printf("%d ", present->num);
		previous = present;
		present = present->next;
	}
}
int judge(Swadia* head, int num)
{
	Swadia* present = head; Swadia* previous = head; 
	while (present != NULL)
	{
		if (num == present->num)
		{
			return 1;
		}
		else
		{
			previous = present;
			present = present->next;
		}
	}
	return 0;
}
Swadia* insert(Swadia* head, int num)
{
	Swadia* present = NULL;
	static Swadia* tail = NULL;
	present = (Swadia*)malloc(sizeof(Swadia));
	present->num = num;
	if (tail != NULL) tail->next = present;
	tail = present;
	tail->next = NULL;
	if (head == NULL) head = present;
	return head;
}