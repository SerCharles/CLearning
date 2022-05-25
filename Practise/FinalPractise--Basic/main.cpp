#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node
{
	char name[30], pro[20];
	int power;
	Node* next; Node* last;
};
int n;
Node* build();
Node* sort(Node* head);
Node* turn(Node* head, int begin, int end);
Node* del(Node* head, int place);
Node* add(Node* head, int place);
void swap(Node* pa, Node* pb);
void print(Node* head);
int main()
{
	Node* head;
	head = build();
	scanf("%d", &n);
	int i;
	for (i = 1; i <= n; i++)
	{
		char type[3] = { 0 };
		int p = 0, q = 0;
		scanf("%s", type);
		if (type[0] == 'S')
		{
			head = sort(head);
		}
		else if (type[0] == 'D')
		{
			scanf("%d", &p);
			head = del(head, p);
		}
		else if (type[0] == 'A')
		{
			scanf("%d", &p);
		    head = add(head, p);
		}
		else if (type[0] == 'T')
		{
			scanf("%d%d", &p, &q);
			head = turn(head, p, q);
		}
	}
	print(head);
	while (1);
	return 0;
}
Node* build()
{
	Node* head = NULL; Node* the = NULL; Node* previous = NULL;
	while (1)
	{
		char a[30] = { 0 };
		scanf("%s", a);
		if (a[0] == 'e'&&a[1] == 'n'&&a[2] == 'd'&&a[3] == 0) break;
		else
		{
			the = (Node*)malloc(sizeof(Node));
			strcpy(the->name, a);
			scanf("%s%d", the->pro, &the->power);
			if (head == NULL)
			{
				head = the;
				previous = the;
				the->last = NULL;
			}
			else
			{
				previous->next = the;
				the->last = previous;
				previous = the;
			}
		}
	}
	previous->next = NULL;
	return head;
}
Node* sort(Node* head)
{
	Node* the = head; Node* previous = head;
	if (the->next == NULL || the == NULL) return head;
	else
	{
		while (the->next != NULL)
		{
			Node* flag = the->next;
			while (flag != NULL)
			{
				if (the->power > flag->power) swap(the, flag);
				flag = flag->next;
			}
			the = the->next;
		}
	}
	return head;
}
Node* turn(Node* head, int begin, int end)
{
	int num=1;
	Node* the = head; Node* previous = head; Node* turn_t = NULL; Node* turn_h = NULL; Node* theback = NULL;
	if (head == NULL || head->next == NULL) return head;
	else
	{
		while (the != NULL)
		{
				if (num == begin)
				{
					turn_h = the;
				}
				else if (num == end)
				{
					turn_t = the;
				}
				previous = the; the = the->next;
				num++;
		}
		the = turn_h; theback = turn_t;
		while (1)
		{
			if (the == theback || the->last == theback) break;
			swap(the, theback);
			the = the->next; theback = theback->last;
		}
	}
	return head;
}
Node* del(Node* head, int place)
{
	Node* the = head; Node* previous = head;
	int num = 1;
	if (the == NULL||the->next==NULL) return NULL;
	else
	{
		while (the != NULL)
		{
			if (num == place)
			{
				if (the == head)
				{
					the->next->last = NULL;
					head = the->next;
				}
				else if (the->next == NULL)
				{
					previous->next = NULL;
				}
				else
				{
					previous->next = the->next;
					the->next->last = previous;
				}
				free(the);
				break;
			}
			else
			{
				previous = the;
				the = the->next;
				num++;
			}
		}
	}
	return head;
}
Node* add(Node* head, int place)
{
	Node* the = head; Node* previous = head; Node* nova = NULL;
	nova = (Node*)malloc(sizeof(Node));

	int num = 1;
	scanf("%s %s %d", nova->name, nova->pro, &nova->power);
	if (the == NULL)
	{
		head = nova;
		head->next = NULL; head->last = NULL; 
		return head;
	}
	if (place == 1)
	{
		nova->next = head;
		head = nova;
		nova->last = NULL;
		return head;
	}
	while (the != NULL)
	{
		if (num == place - 1)
		{
			if (the->next == NULL)
			{
				the->next = nova;
				nova->last = the;
				nova->next = NULL;
				break;
			}
			else
			{
				nova->last = the;
				nova->next = the->next;
				nova->next->last = nova;
				nova->last->next = nova;
				break;
			}
		}
		else
		{
			previous = the;
			the = the->next;
			num++;
		}
	}
	return head;
}
void print(Node* head)
{
	Node* the = head; Node* previous = head;
	while (the != NULL)
	{
		printf("%s %s %d\n", the->name, the->pro, the->power);
		the->last = NULL;
		previous = the;
		the = the->next;
		free(previous);
	}
}
void swap(Node* pa, Node* pb)
{
	int temp_power;
	char temp_name[30], temp_pro[20];
	temp_power = pa->power; strcpy(temp_name, pa->name); strcpy(temp_pro, pa->pro);
	pa->power = pb->power; strcpy(pa->name, pb->name); strcpy(pa->pro, pb->pro);
	pb->power = temp_power; strcpy(pb->name, temp_name); strcpy(pb->pro, temp_pro);
}
