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