extern "C"
{
#include "./../../include/list.hpp"
#include <stdint.h>
}

#include <gtest/gtest.h>

TEST(ListTests, push) {

	List list;
	list.append(1);
	EXPECT_EQ(1, list.pop());
}
