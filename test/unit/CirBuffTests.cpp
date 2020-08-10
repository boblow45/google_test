extern "C"
{
#include "./../../include/circular_buffer.h"
#include <stdint.h>
}

#include <gtest/gtest.h>

TEST(CircularBufferTests, cbuf_init) {
	uint8_t buffer[8];
	uint32_t size = sizeof(buffer) / sizeof(buffer[0]);
	cbuf_handle_t cbuf = cbuf_init(buffer, size);

	ASSERT_EQ(8, cbuf->max);
	ASSERT_EQ(buffer, cbuf->buffer);
	ASSERT_EQ(0, cbuf->tail);
	ASSERT_EQ(0, cbuf->head);
	ASSERT_EQ(false, cbuf->full);
}

TEST(CircularBufferTests, cbuf_add) {
	uint8_t buffer[2];
	uint32_t size = sizeof(buffer) / sizeof(buffer[0]);
	cbuf_handle_t cbuf = cbuf_init(buffer, size);

	cbuf_put(cbuf, 42);
	ASSERT_EQ(false, cbuf->full);
	ASSERT_EQ(1, cbuf->head);
	ASSERT_EQ(42, cbuf->buffer[0]);

	cbuf_put(cbuf, 84);
	ASSERT_EQ(true, cbuf->full);
	ASSERT_EQ(0, cbuf->head);
	ASSERT_EQ(84, cbuf->buffer[1]);
	ASSERT_EQ(cbuf->head, cbuf->tail);
}

TEST(CircularBufferTests, cbuf_get) {
	uint8_t buffer[2];
	uint32_t size = sizeof(buffer) / sizeof(buffer[0]);
	cbuf_handle_t cbuf = cbuf_init(buffer, size);

	cbuf_put(cbuf, 42);
	cbuf_put(cbuf, 84);
	ASSERT_EQ(0, cbuf->tail);
	ASSERT_EQ(true, cbuf->full);

	uint8_t data;
	cbuf_get(cbuf, &data);
	ASSERT_EQ(42, data);
	ASSERT_EQ(1, cbuf->tail);
	ASSERT_EQ(false, cbuf->full);
}

TEST(CircularBufferTests, cbuf_get_capacity) {
	uint8_t buffer[2];
	uint32_t size = sizeof(buffer) / sizeof(buffer[0]);
	cbuf_handle_t cbuf = cbuf_init(buffer, size);

	ASSERT_EQ(2, cbuf_capacity(cbuf));
}

TEST(CircularBufferTests, full_or_empty_test) {
	uint8_t buffer[3];
	uint32_t size = sizeof(buffer) / sizeof(buffer[0]);
	cbuf_handle_t cbuf = cbuf_init(buffer, size);

	ASSERT_EQ(true, cbuf_empty(cbuf));

	cbuf_put(cbuf, 1);
	cbuf_put(cbuf, 2);
	cbuf_put(cbuf, 3);
	ASSERT_EQ(true, cbuf_full(cbuf));
}

TEST(CircularBufferTests, cbuf_size) {
	uint8_t buffer[3];
	uint32_t size = sizeof(buffer) / sizeof(buffer[0]);
	cbuf_handle_t cbuf = cbuf_init(buffer, size);

	ASSERT_EQ(0, cbuf_size(cbuf));
	cbuf_put(cbuf, 1);
	ASSERT_EQ(1, cbuf_size(cbuf));
	cbuf_put(cbuf, 2);
	cbuf_put(cbuf, 3);
	ASSERT_EQ(3, cbuf_size(cbuf));
	cbuf_put(cbuf, 4);
	ASSERT_EQ(3, cbuf_size(cbuf));
}