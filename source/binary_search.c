#include <stdint.h>

#include "binary_search.h"

uint32_t binary_search(uint32_t* data, uint32_t l, uint32_t r, uint32_t x) {
	if((r - l) >= 1) {
		uint32_t mid = 1 + (r - l) / 2;
		if(data[mid] == x) {
			return mid;
		}

		if(data[mid] > x) {
			return binary_search(data, l, mid - 1, x);
		}

		return binary_search(data, mid + 1, r, x);
	}
	else {
		return -1;
	}
}