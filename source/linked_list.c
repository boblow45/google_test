#include <stdint.h>
#include <stdlib.h>

#include "linked_list.h"

node_t* create(int32_t val) {
	node_t* node = (node_t*)malloc(sizeof(node_t));
	node->val = val;
	node->next = NULL;
	return node;
}

void push(node_t** head, int32_t val) {
	node_t* new_node = create(val);

	// Add the new node to the front of the linked list.
	new_node->next = *head;
	// change the pointer which was passed in to the new head
	*head = new_node;
}

int32_t pop(node_t** head) {

	// Check to ensure that the head passed to the function is not null.
	// Can't dereference a NULL pointer.
	if(*head == NULL) {
		return -1;
	}

	// Head is not null, so we need to save the next value before freeing the alocated memory.
	node_t* next_val = (*head)->next;
	// Get the value from the head before it is freed
	int32_t val = (*head)->val;
	// free the head node as the value has been recived
	free(*head);
	*head = next_val;
	return val;
}

int32_t remove_last(node_t* head) {

	node_t* current = head;
	int32_t ret_val;

	if(current->next == NULL) {
		ret_val = current->val;
		free(current);
		return ret_val;
	}

	while(current->next->next != NULL) {
		current = current->next;
	}

	ret_val = current->next->val;
	free(current->next);
	current->next = NULL;
	return ret_val;
}

int32_t remove_by_index(node_t** head, uint32_t n) {

	node_t* current = *head;
	node_t* tmp = NULL;

	if(n == 0) {
		return pop(head);
	}

	uint32_t i = 0;
	for(i = 0; i < n - 1; i++) {
		if(current->next == NULL) {
			return -1;
		}
		current = current->next;
	}

	tmp = current->next;
	current->next = current->next->next;

	int32_t ret_val = tmp->val;
	free(tmp);
	return ret_val;
}

void remove_by_value(node_t** head, uint32_t val) {

	node_t* current = *head;
	node_t* tmp;
	while(current->next->next != NULL) {
		if(current->next->val == val) {
			tmp = current->next;
			current->next = current->next->next;
			free(tmp);
			return;
		}
	}

	if(current->next->val == val) {
		free(current->next);
		current->next = NULL;
		return;
	}
}