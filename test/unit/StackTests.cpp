extern "C"
{
#include "./../../include/stack.h"
#include <stdint.h>
}

#include <gtest/gtest.h>

TEST(StackTests, create) {

	int32_t buffer[8];
	stack_tt* stack = create_stack(buffer, sizeof(buffer) / sizeof(buffer[0]));
	EXPECT_EQ(buffer, stack->buffer);
	EXPECT_EQ(8, stack->capacity);
	EXPECT_EQ(0, stack->num_items);
}

TEST(StackTests, push_stack) {

	int32_t buffer[4];
	stack_tt* stack = create_stack(buffer, sizeof(buffer) / sizeof(buffer[0]));

	push_stack(stack, 42);
	EXPECT_EQ(1, stack->num_items);
	EXPECT_EQ(42, stack->buffer[0]);

	push_stack(stack, 43);
	EXPECT_EQ(2, stack->num_items);
	EXPECT_EQ(43, stack->buffer[1]);
}

TEST(StackTests, pop_stack) {

	int32_t buffer[4];
	stack_tt* stack = create_stack(buffer, sizeof(buffer) / sizeof(buffer[0]));

	EXPECT_EQ(-1, pop_stack(stack));

	push_stack(stack, 42);

	EXPECT_EQ(42, pop_stack(stack));
	EXPECT_EQ(0, stack->num_items);
}

TEST(StackTests, peek_stack) {

	int32_t buffer[4];
	stack_tt* stack = create_stack(buffer, sizeof(buffer) / sizeof(buffer[0]));

	EXPECT_EQ(-1, peek_stack(stack));

	push_stack(stack, 42);

	EXPECT_EQ(42, peek_stack(stack));
	EXPECT_EQ(1, stack->num_items);
}

TEST(StackTests, is_full) {

	int32_t buffer[2];
	stack_tt* stack = create_stack(buffer, sizeof(buffer) / sizeof(buffer[0]));

	EXPECT_EQ(true, is_stack_empty(stack));
	EXPECT_EQ(false, is_stack_full(stack));

	push_stack(stack, 42);
	EXPECT_EQ(false, is_stack_empty(stack));
	EXPECT_EQ(false, is_stack_full(stack));

	push_stack(stack, 43);
	EXPECT_EQ(false, is_stack_empty(stack));
	EXPECT_EQ(true, is_stack_full(stack));
}