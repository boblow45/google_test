
extern "C"
{
#include "./../../include/example.h"
}

#include <gtest/gtest.h>

TEST(ExampleTests, MAC) {
	int x = 43;
	int y = 16;
	int sum = 100;
	int oldSum = sum;
	int expectedNewSum = oldSum + x * y;

	EXPECT_EQ(oldSum + x * y, MAC(x, y, &sum));

	EXPECT_EQ(expectedNewSum, sum);
}

// TEST(BinSearchTests, binary_search) {
// 	uint32_t arr[] = {2, 3, 4, 10, 40};
// 	uint32_t x = 10;
// 	uint32_t n = sizeof(arr) / sizeof(arr[0]);
// 	uint32_t result = binary_search(arr, 0, n - 1, x);

// 	EXPECT_EQ(3, result);
// }