extern "C"
{
#include "./../../include/binary_search.h"
#include <stdint.h>
}

#include <gtest/gtest.h>

TEST(BinSearchTests, binary_search) {
	uint32_t arr[] = {2, 3, 4, 10, 40};
	uint32_t x = 10;
	uint32_t n = sizeof(arr) / sizeof(arr[0]);
	uint32_t result = binary_search(arr, 0, n - 1, x);

	EXPECT_EQ(3, result);

	x = 20;
	result = binary_search(arr, 0, n - 1, x);
	EXPECT_EQ(-1, result);

	x = 1;
	result = binary_search(arr, 0, n - 1, x);
	EXPECT_EQ(-1, result);

	x = 3;
	n = 3;
	result = binary_search(arr, 0, n - 1, x);
	EXPECT_EQ(1, result);
}