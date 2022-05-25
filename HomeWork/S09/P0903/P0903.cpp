#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Swadia
{
	int num;
	int times;
	Swadia* next;
};
int n1, n2, ans = 0;
Swadia* build(int num);
void print(Swadia* head);
Swadia* insert(Swadia*head, int num, int, int* sum);
Swadia* delete_zero(Swadia* head, int* sum);
int main()
{
	scanf("%d", &n1);
	Swadia* head = NULL;
	head = build(n1);
	ans = n1;
	scanf("%d", &n2);
	for (int i = 1; i <= n2; i++)
	{
		int s1, s2;
		scanf("%d%d", &s1, &s2);
		head = insert(head, s1, s2, &ans);
	}
	head = delete_zero(head, &ans);
	printf("%d\n", ans);
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
		scanf("%d%d", &present->num, &present->times);
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
		printf("%d %d\n", present->num, present->times);
		previous = present;
		present = present->next;
	}
}
Swadia* insert(Swadia*head, int num, int times, int* sum)
{
	Swadia* present = head; Swadia* previous = head; Swadia* nova;
	while (present != NULL)
	{
		if (times < head->times)
		{
			nova = (Swadia*)malloc(sizeof(Swadia));
			nova->num = num;
			nova->times = times;
			nova->next = head;
			ans++;
			head = nova;
			return head;
		}
		else if (times < present->times)
		{
			nova = (Swadia*)malloc(sizeof(Swadia));
			nova->num = num;
			nova->times = times;
			previous->next = nova;
			nova->next = present;
			ans++;
			return head;
		}
		else if (times == present->times)
		{
			present->num += num;
			return head;
		}
		else if (times > present->times)
		{
			previous = present;
			present = present->next;
		}
	}
	nova = (Swadia*)malloc(sizeof(Swadia));
	nova->num = num;
	nova->times = times;
	nova->next = NULL;
	previous->next = nova;
	ans++;
	return head;
}
Swadia* delete_zero(Swadia* head, int* sum)
{
	Swadia* present = head; Swadia* previous = head;
	if (head == NULL) return head;
	if (head->next == NULL)
	{
		if (head->num == 0)
		{
			ans = 0;
			return NULL;
		}
		else return head;
	}
	else
	{
		while (present != NULL)
		{
			if (head->num == 0)
			{
				head = head->next;
				present = head; previous = head;
				ans--;
			}
			else
			{
				if (present->num != 0)
				{
					previous = present;
					present = present->next;
				}
				else
				{
					previous->next = present->next;
					free(present);
					present = previous->next;
					ans--;
				}
			}
		}
	}
	return head;
}