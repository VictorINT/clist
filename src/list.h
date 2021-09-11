#include <stdlib.h>
#include <stdio.h>

struct Node
{
	int value;
	struct Node* next;	
};

typedef enum { F, T } bool;
static bool hr = F;

#define List struct Node*

struct Node* lnew();
void lprint(struct Node* head);
void linsert(struct Node ** head, int x, int n);
void lfpush(struct Node ** head, int x);
int lfpop(struct Node ** head);
void lbpush(struct Node ** head, int x);
int lbpop(struct Node* head);
void rm(struct Node* head, int index);
struct Node* lpat(struct Node* head, int index);
int lvat(struct Node* head, int index);
