#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node
{
	char number[30];
	char name[30];
	char gender[30];
	int score;
	int rank;
	Node* next;
};
Node* build(int m);
Node* sort(Node* head);
Node* renew(Node* head);
Node* del(Node* head, int num);
void print(Node* head);
void swap(Node* a1, Node* a2);
int compare(Node* a1, Node* a2);
int main()
{
	int n, m,num;
	char s[10];
	scanf("%d", &m);
	Node* head = build(m);
	head = sort(head);
	head = renew(head);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", s);
		scanf("%d", &num);
		head = del(head, num);
	}
	print(head);
	return 0;
}
Node* build(int m)
{
	Node* head = NULL; Node* the = NULL; Node* previous = NULL;
	int i;
	for (i = 1; i <= m; i++)
	{
		the = (Node*)malloc(sizeof(Node));
		scanf("%s", the->number);
		scanf("%s", the->name);
		scanf("%s", the->gender);
		scanf("%d", &the->score);
		the->rank = 0;
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
void print(Node* head)
{
	Node* the = head; Node* previous = head;
	while (the != NULL)
	{
		printf("%s ", the->number);
		printf("%s ", the->name);
		printf("%s ", the->gender);
		printf("%d\n", the->score);
		//free(the);
		the = the->next;
	}
}
Node* sort(Node* head)
{
	Node* the = head; Node* previous = head; Node*flag = the->next;
	if (the->next == NULL || the == NULL) return head;
	while (the->next != NULL)
	{
		flag = the->next;
		while (flag != NULL)
		{
			if (the->score < flag->score)
			{
				swap(the, flag);
			}
			else if (the->score == flag->score&&compare(the, flag) == 1)
			{
				swap(the, flag);
			}
			flag = flag->next;
		}
		the = the->next;
	}
	return head;
}
void swap(Node* a1, Node* a2)
{
	char NUMBER[30] = { 0 }, NAME[30] = { 0 }, GENDER[30] = { 0 };
	int SCORE = 0;
	memcpy(NUMBER, a1->number, sizeof(a1->number));
	memcpy(NAME, a1->name, sizeof(a1->name));
	memcpy(GENDER, a1->gender, sizeof(a1->gender));
	SCORE = a1->score;
	memcpy(a1->number, a2->number, sizeof(a2->number));
	memcpy(a1->name, a2->name, sizeof(a2->name));
	memcpy(a1->gender, a2->gender, sizeof(a2->gender));
	a1->score = a2->score;
	memcpy(a2->number, NUMBER, sizeof(NUMBER));
	memcpy(a2->name, NAME, sizeof(NAME));
	memcpy(a2->gender, GENDER, sizeof(GENDER));
	a2->score = SCORE;
}
int compare(Node* a1, Node* a2)
{
	int i;
	for (i = 0; i < 30; i++)
	{
		if (a1->number[i] > a2->number[i]) return 1;
		else if (a1->number[i] < a2->number[i]) return -1;
	}
	return 0;
}
Node* renew(Node* head)
{
	int flag = 1;
	Node* the = head->next; Node* previous = head;
	if (head == NULL) return head;
	head->rank = 1;
	while (the != NULL)
	{
		if (the->score == previous->score)
		{
			the->rank = previous->rank;
			flag++;
		}
		else
		{
			the->rank = previous->rank + flag;
			flag = 1;
		}
		previous = the;
		the = the->next;
	}
	return head;
}
Node* del(Node* head, int num)
{
	Node* the = head; Node* previous = head;
	if (head == NULL) return head;
	while (the != NULL)
	{
		if (the->rank == num)
		{
			if (the == head)
			{
				head = the->next;
				//free(the);
				the = head; previous = head;
			}
			else
			{
				previous->next = the->next;
				//free(the);
				the = previous->next;
			}
		}
		else
		{
			previous = the;
			the = the->next;
		}
	}
	return head;
}