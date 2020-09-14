extern "C"
{
#include "./../../include/linked_list.h"
#include <stdint.h>
}

#include <gtest/gtest.h>

TEST(LinkedListTests, create) {

	node_t* linked_list = create(42);
	EXPECT_EQ(42, linked_list->val);
	EXPECT_EQ(NULL, linked_list->next);
}

TEST(LinkedListTests, push) {

	node_t* linked_list = create(42);
	push(&linked_list, 43);

	EXPECT_EQ(43, linked_list->val);
	EXPECT_EQ(42, linked_list->next->val);
	EXPECT_EQ(NULL, linked_list->next->next);
}

TEST(LinkedListTests, pop) {

	node_t* linked_list = create(42);
	push(&linked_list, 43);

	EXPECT_EQ(43, pop(&linked_list));
	EXPECT_EQ(42, pop(&linked_list));
}

TEST(LinkedListTests, remove_last) {

	node_t* linked_list = create(42);
	push(&linked_list, 43);
	push(&linked_list, 44);

	EXPECT_EQ(42, remove_last(linked_list));
	EXPECT_EQ(NULL, linked_list->next->next);
}

TEST(LinkedListTests, remove_by_index) {

	node_t* linked_list = create(42);
	push(&linked_list, 43);
	push(&linked_list, 44);

	EXPECT_EQ(43, remove_by_index(&linked_list, 1));
	EXPECT_EQ(NULL, linked_list->next->next);
}