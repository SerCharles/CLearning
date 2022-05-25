#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node
{
	int num;
	Node* next;
};
int sum,time;
Node* tail = NULL;
Node* build(int num);
Node* del(Node* head);
int main()
{
	scanf("%d%d", &sum,&time);
	Node* head = build(sum);
		head=del(head);
		printf("%d", head->num);
		return 0;
}
Node* build(int num)
{
	Node* head = NULL;
	Node* the = NULL; Node* previous = NULL;
	for (int i = 1; i <= num; i++)
	{
		the = (Node*)malloc(sizeof(Node));
		the->num = i;
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
	previous->next = head;
	tail = previous;
	return head;
}
Node* del(Node* head)
{
	Node* the = head; Node* previous = tail;
	while (sum > 1)
	{
		int t = time%sum;
		if (t == 0) t += sum;
		while (t > 0)
		{
			t--;
			if (t == 0)
			{
				if (the == head)
				{
					previous->next = the->next;
					the = the -> next;
					head = the;
				}
				else if (the == tail)
				{
					previous->next = head;
					the = head;
					tail = previous;
				}
				else
				{
					previous->next = the->next;
					the = the->next;
				}
				break;
			}
			previous = the;
			the = the->next;
		}
		sum--;
	}
	return head;
}
