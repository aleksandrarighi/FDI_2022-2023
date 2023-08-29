#include "byteswap.h"

uint32_t byteswap(uint32_t n) {
	uint32_t result = 0;

	result = result | (n & 0x000000FF) << 24;
	result = result | (n & 0x0000FF00) << 8;
	result = result | (n & 0x00FF0000) >> 8;
	result = result | (n & 0xFF000000) >> 24;

	return result;

}