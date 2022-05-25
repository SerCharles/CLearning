#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Swadia
{
	int num;
Swadia* next;
};
int n;
Swadia* build(int num);
Swadia* DeleteOverlap(Swadia* head);
void print(Swadia* head);
int main()
{
	scanf("%d", &n);
	Swadia* head=NULL;
	head = build(n);
	head = DeleteOverlap(head);
	print(head);
	return 0;
}
Swadia* build(int num)
{
	int i,s;
	Swadia* head = NULL; Swadia*present = NULL; Swadia*previous = NULL;
	for (i = 1; i <= num; i++)
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
	present->next = NULL;
	return head;
}
void print(Swadia* head)
{
	Swadia* previous = head; Swadia*present = head;
	while (present != NULL)
	{
		printf("%d ", present->num);
		previous = present;
		present = present->next;
	}
}
Swadia* DeleteOverlap(Swadia* head)
{
	Swadia* previous = head; Swadia*present = head->next;
	if (head == NULL)return NULL;
	else if (head->next == NULL) return head;
	else
	{
		while (present != NULL)
		{
			if (present->num == previous->num)
			{
				previous->next = present->next;
				free(present);
				present = previous->next;
			}
			else
			{
				previous = present;
				present = present->next;
			}
		}
	}
	return head;
}