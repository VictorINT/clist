#include "list.h"

void allocate(struct Node ** to_allocate)
{
	(*to_allocate) = (struct Node*)malloc(sizeof(struct Node));
}

void error_handle(char * arr)
{
	while((*arr) != '\0')
	{
		printf("%c", *arr);
		arr++;
	}	
	printf("\n");
	exit(0);
}

struct Node * lnew()
{
	struct Node* head = NULL;
	return head;
}

void lprint(struct Node * head)
{
	struct Node* temp = head;
	while(temp != NULL)
	{
		printf("%d ", temp->value);
		temp=temp->next;
	}	
}

void linsert(struct Node ** head, int x, int n)
{
	if(n == 1 && (*head) == NULL)
	{
		allocate(head);
		(*head)->value = x;
	}
	else
	{
		struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node));
		temp1->value = x;
		temp1->next = NULL;
		if(n == 1)
		{
			temp1->next = *head;
			*head = temp1;
			return;
		}
		struct Node* temp2 = *head;
		for(int i = 0; i < n-2; i++)
		{
			if(temp2->next != NULL)
				temp2 = temp2->next;
			else
				error_handle("Index out of bounds");
		}
		temp1->next = temp2->next;
		temp2->next = temp1;
	}
}

void lfpush(struct Node ** head, int x)
{
	if((*head) == NULL)
	{
		allocate(head);
		(*head)->value = x;
	}
	else
	{
		struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
		temp->value = x;
		temp->next = (*head);
		(*head) = temp;
	}
}

int lfpop(struct Node ** head)
{
	if((*head)->next == NULL) // ?
	{
		error_handle("List is empty! No nodes to pop");
	}
	else
	{
		struct Node* tbf = (*head);
		int r = tbf->value;
		(*head) = tbf->next;
		free(tbf);
		return r;
	}
}

void lbpush(struct Node ** head, int x)
{
	if((*head) == NULL)
	{
		allocate(head);
		(*head)->value = x;
	}
	else
	{
		struct Node* temp = *head;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		struct Node* temp2 = (struct Node*)malloc(sizeof(struct Node));
		temp2->value = x;
		temp2->next = NULL;
		temp->next = temp2;
	}
}

int lbpop(struct Node * head)
{
	if(head->next == NULL) // ?
	{
		error_handle("List is empty! No nodes to pop");
	}
	else
	{
		struct Node* temp = head;
		while(temp->next->next != NULL)
		{
			temp = temp->next;
		}
		struct Node* tbf = temp->next;
		int r = temp->next->value;
		temp->next = NULL;
		free(tbf);
		return r;
	}
}

void lrm(struct Node ** head, int index)
{
	if(index < 0)
	{
		error_handle("Invalid index");
	}
	if(index == 0)
	{
		lfpop(head);
	}
	else
	{
		struct Node* temp = *head;
		for(int i = 0; i < index - 1; i++)
		{
			if(temp->next != NULL)
				temp = temp->next;
			else
				error_handle("Index out of bounds");
		}
		struct Node* tbf = temp->next;
		temp->next = temp->next->next;
		free(tbf);
	}
}

void lrmrng(struct Node ** head, int start, int end)
{
	if(start < 0)
	{
		error_handle("Invalid index");
	}
	if(start == end)
	{
		lrm(head, start - 1);
	}
	else
	{
		struct Node* endtemp = *head;
		struct Node* starttemp = *head;
		for(int i = 0; i <= end - 1; i++)
		{
			if(i < start - 2)
			{
		 		starttemp = starttemp->next;
			}
			if(endtemp->next != NULL)
			{
				endtemp = endtemp->next;
			}	
			else
			{
				error_handle("Index out of bounds");
			}	
		}
		// for(int i = start; i < end; i++)
		// {
		// 	starttemp = starttemp->next;
		// 	struct Node* tbf = starttemp;
		// 	starttemp->next = starttemp->next->next; // bug here
		// 	free(tbf);
		// }
		starttemp->next = endtemp;
	}
}

struct Node * lpat(struct Node* head, int index)
{
	struct Node* temp = head;
	if(index == 0)
	{
		return head;
	}
	for(int i = 0; i < index - 1; i++)
	{
		if(temp->next != NULL)
			temp = temp->next;
		else
			error_handle("Index out of bounds");
	}
	return temp->next;
}

int lvat(struct Node * head, int index)
{
	return lpat(head, index)->value;
}

void lreverse(struct Node ** head)
{
	struct Node *temp, *prev, *current, *next;
	current = (*head);
	prev = NULL;
	while(current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head = prev;
}

int get_sum(struct Node * head)
{
	int sum = 0;
	while(head != NULL)
	{
		sum += head->value;
		head = head->next;
	}
	return sum;
}

int get_mul(struct Node * head)
{
	int mul = 0;
	while(head != NULL)
	{
		mul *= head->value;
		head = head->next;
	}
	return mul;
}

int lsize(struct Node * head)
{
	int size = 0;
	while(head != NULL)
	{
		size++;
		head = head->next;
	}
	return size;
}