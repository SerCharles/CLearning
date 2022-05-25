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
void print(Swadia* head);
Swadia* insert(Swadia*head, int num);
Swadia* del(Swadia*head, int num);
int main()
{
	scanf("%d", &n1);
	Swadia* head = NULL;
	head = build(n1);
	scanf("%d", &n2);
	for (int i = 1; i <= n2; i++)
	{
		int num, whether;
		scanf("%d%d", &num, &whether);
		if (whether == 1)
		{
			head = insert(head, num);
		}
		else
		{
			head = del(head, num);
		}
	}
	print(head);
	return 0;
}
Swadia* build(int num)
{
	int i, s;
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
		printf("%d\n", present->num);
		previous = present;
		present = present->next;
	}
}
Swadia* insert(Swadia*head, int num)
{
	Swadia* present = head; Swadia* previous = head; Swadia* nova;
	while (present != NULL)
	{
		if (num < head->num)
		{
			nova = (Swadia*)malloc(sizeof(Swadia));
			nova->num = num;
			nova->next = head;
			head = nova;
			return head;
		}
		else if (num < present->num)
		{
			nova = (Swadia*)malloc(sizeof(Swadia));
			nova->num = num;
			previous->next = nova;
			nova->next = present;
			return head;
		}
		else if (num == present->num)
		{
			return head;
		}
		else if (num > present->num)
		{
			previous = present;
			present = present->next;
		}
	}
	nova = (Swadia*)malloc(sizeof(Swadia));
	nova->num = num;
	nova->next = NULL;
	previous->next = nova;
	return head;
}
Swadia* del(Swadia*head, int num)
{
	Swadia* present = head; Swadia* previous = head;
	if (head == NULL) return head;
	if (head->next == NULL)
	{
		if (head->num == num)
		{
			return NULL;
		}
		else return head;
	}
	else
	{
		while (present != NULL)
		{
			if (head->num == num)
			{
				head = head->next;
				present = head; previous = head;
			}
			else
			{
				if (present->num != num)
				{
					previous = present;
					present = present->next;
				}
				else
				{
					previous->next = present->next;
					free(present);
					present = previous->next;
				}
			}
		}
	}
	return head;
}