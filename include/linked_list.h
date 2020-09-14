#ifndef __LINK_LIST__
#define __LINK_LIST__

#include <stdint.h>

typedef struct node {
	int32_t val;
	struct node* next;
} node_t;

node_t* create(int32_t val);
void push(node_t** head, int32_t val);
int32_t pop(node_t** head);
int32_t remove_last(node_t* head);
int32_t remove_by_index(node_t** head, uint32_t n);
void remove_by_value(node_t** head, uint32_t val);

#endif // __LINK_LIST__