#include <stdlib.h>
#include <stdio.h>

struct Node
{
	int value;
	struct Node * next;	
};

#define List struct Node *

struct Node * lnew();

void lprint(struct Node * head);

void linsert(struct Node ** head, int x, int n);

void lfpush(struct Node ** head, int x);

int lfpop(struct Node ** head);

void lbpush(struct Node ** head, int x);

int lbpop(struct Node * head);

void lrm(struct Node ** head, int index);

void lrmrng(struct Node ** head, int start, int end);

struct Node * lpat(struct Node * head, int index);

int lvat(struct Node * head, int index);

void lreverse(struct Node ** head);

int get_sum(struct Node * head);

int get_mul(struct Node * head);

int lsize(struct Node * head);