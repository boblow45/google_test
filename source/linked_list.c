#include <stdint.h>
#include <stdlib.h>

#include "linked_list.h"

node_t* create(int32_t val) {
	node_t* node = (node_t*)malloc(sizeof(node_t));
	node->val = val;
	node->next = NULL;
	return node;
}