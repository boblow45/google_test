#ifndef __STACK__
#define __STACK__

#include <stdbool.h>
#include <stdint.h>

typedef struct stack {
	int32_t* buffer;
	uint32_t capacity;
	uint32_t num_items;
} stack_tt;

stack_tt* create_stack(int32_t* buffer, uint32_t capacity);
bool is_stack_full(stack_tt* stack);
bool is_stack_empty(stack_tt* stack);
void push_stack(stack_tt* stack, int32_t item);
int32_t pop_stack(stack_tt* stack);
int32_t peek_stack(stack_tt* stack);

#endif // __STACK__