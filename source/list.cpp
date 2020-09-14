#include <cstdint>
#include <cstdlib>

#include "list.hpp"

List::List() {
	this->size = 4;
	this->buffer = (uint32_t*)malloc(sizeof(uint32_t) * this->size);
	this->num_eles = 0;
}

void List::append(uint32_t val) {
	this->buffer[this->num_eles++] = val;
}

uint32_t List::pop(void) {
	return this->buffer[--this->num_eles];
}