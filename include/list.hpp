#ifndef __LIST__
#define __LIST__

#include <cstdint>

class List {
private:
	uint32_t* buffer;
	uint32_t size;
	uint32_t num_eles;

public:
	List();
	void append(uint32_t val);
	uint32_t pop(void);
};

#endif // __LIST__