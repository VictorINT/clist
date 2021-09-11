#include "list.h"

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

struct Node* lnew()
{
	struct Node* head = NULL; 
	head = (struct Node*)malloc(sizeof(struct Node));
	return head;
}

void lprint(struct Node* head)
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
	if((*head)->next->next == NULL && hr == F)
	{
		lfpop(head);
		hr = T;
	}
}

void lfpush(struct Node ** head, int x)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->value = x;
	temp->next = (*head);
	(*head) = temp;
	if((*head)->next->next == NULL && hr == F)
	{
		lfpop(head);
		hr = T;
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
	struct Node* temp = *head;
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	struct Node* temp2 = (struct Node*)malloc(sizeof(struct Node));
	temp2->value = x;
	temp2->next = NULL;
	temp->next = temp2;
	if((*head)->next->next == NULL && hr == F)
	{
		lfpop(head);
		hr = T;
	}
}

int lbpop(struct Node* head)
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

void rm(struct Node* head, int index)
{
	struct Node* temp = head;
	for(int i = 0; i < index - 2; i++)
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

struct Node* lpat(struct Node* head, int index)
{
	struct Node* temp = head;
	for(int i = 0; i < index - 1; i++)
	{
		if(temp->next != NULL)
			temp = temp->next;
		else
			error_handle("Index out of bounds");
	}
	return temp->next;
}

int lvat(struct Node* head, int index)
{
	return lpat(head, index)->value;
}
