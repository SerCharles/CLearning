#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int n,m;
struct Node
{
	char code[20], name[20], sex[10];
	int score,rank;
	Node* last;Node* next;
};
Node* build();
Node* sort(Node* head);
Node* getrank(Node* head);
Node* del(Node* head, int place);
void print(Node* head);
void swap(Node* a, Node* b);
int compare(char str1[20],char str2[20]);
int main()
{
	Node* head;
	char a[10], place, i;
	scanf("%d", &n);
	head = build();
	head = sort(head);
	head = getrank(head);
	scanf("%d", &m);
	for (i = 1; i <= m; i++)
	{
		scanf("%s%d", a, &place);
		head=del(head, place);
		//head = getrank(head);
	}
	print(head);
	return 0;
}
Node* build()
{
	Node* the = NULL; Node* head = NULL; Node* previous = NULL;
	int i;
	for (i = 1; i <= n; i++)
	{
		the = (Node*)malloc(sizeof(Node));
		scanf("%s%s%s%d", the->code, the->name, the->sex, &the->score);
		if (head == NULL)
		{
			head = the;
			head->last = NULL;
			previous = the;
		}
		else
		{
			previous->next = the;
			the->last = previous;
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
		printf("%s %s %s %d\n", the->code, the->name, the->sex, the->score);
		previous = the;
		the = the->next;
		free(previous);
	}
}
Node* sort(Node* head)
{
	Node* the = head; Node* previous = head; Node* flag = head->next;
	if (head == NULL || head->next == NULL) return head;
	while (the != NULL)
	{
		flag = the->next;
		while (flag != NULL)
		{
			if (the->score < flag->score || (the->score == flag->score&&compare(the->code, flag->code)))
			{
				swap(the, flag);
			}
			flag = flag->next;
		}
		the = the->next;
	}
	return head;
}
void swap(Node* a, Node* b)
{
	char temp_code[20], temp_name[20], temp_sex[10];
	int temp;
	strcpy(temp_code, a->code); strcpy(temp_name, a->name); strcpy(temp_sex, a->sex); temp = a->score;
	strcpy(a->code, b->code); strcpy(a->name, b->name); strcpy(a->sex, b->sex); a->score = b->score;
	strcpy(b->code, temp_code); strcpy(b->name, temp_name); strcpy(b->sex, temp_sex); b->score = temp;
}
int compare(char str1[20], char str2[20])
{
	int l1 = strlen(str1), l2 = strlen(str2),len;
	if (l1 > l2) len = l1; 
	else len = l2;
	int i;
	for (i = 0; i < len; i++)
	{
		if (str1[i] > str2[i]) return 1;
		if (str1[i] < str2[i]) return 0;
	}
	return 0;
}
Node* getrank(Node* head)
{
	Node* the = head; Node* previous = head; Node* flag = head->next;
	int numnum = 1;
	while (the != NULL)
	{
		if (head == the) the->rank = 1;
		else
		{
			if (the->score == previous->score)
			{
				the->rank = previous->rank;
				numnum++;
			}
			else
			{
				the->rank = previous->rank + numnum;
				numnum = 1;
			}
		}
		previous = the;
		the = the->next;
	}
	return head;
}
Node* del(Node* head, int place)
{
	if (head == NULL) return head;
	Node* the = head; Node* previous = head;
	Node* del_pre = NULL; Node* del_last = NULL;
	while (the != NULL)
	{
		if (the->rank == place)
		{
			if (the->rank == 1)
			{
				del_pre = NULL;
			}
			else if (del_pre == NULL)
			{
				del_pre = the->last;
				del_pre->next = NULL;
			}
			if (the->next == NULL)
			{
				del_last = NULL;
			}
			else if (the->next!=NULL&&the->next->rank != place)
			{
				del_last = the->next;
				del_last->last = NULL;
			}
			previous = the;
			the = the->next;
			free(previous);
		}
		else
		{
			previous = the;
			the = the->next;
		}
	}
	if (del_pre == NULL&&del_last == NULL) return NULL;
	else if (del_pre == NULL)
	{
		head = del_last;
		head->last = NULL;
	}
	else if (del_last == NULL)
	{
		del_pre->next = NULL;
	}
	else
	{
		del_pre->next = del_last;
		del_last->last = del_pre;
	}
	return head;
}
