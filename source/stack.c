
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#include "stack.h"

stack_tt* create_stack(int32_t* buffer, uint32_t capacity) {
	stack_tt* stack = (stack_tt*)malloc(sizeof(stack_tt));
	stack->buffer = buffer;
	stack->capacity = capacity;
	stack->num_items = 0;
	return stack;
}

bool is_stack_full(stack_tt* stack) {
	return stack->capacity == stack->num_items;
}

bool is_stack_empty(stack_tt* stack) {
	return stack->num_items == 0;
}

void push_stack(stack_tt* stack, int32_t item) {
	if(is_stack_full(stack)) {
		return;
	}
	stack->buffer[stack->num_items++] = item;
}

int32_t pop_stack(stack_tt* stack) {
	if(is_stack_empty(stack)) {
		return -1;
	}
	return stack->buffer[--stack->num_items];
}

int32_t peek_stack(stack_tt* stack) {
	if(is_stack_empty(stack)) {
		return -1;
	}
	return stack->buffer[stack->num_items - 1];
}