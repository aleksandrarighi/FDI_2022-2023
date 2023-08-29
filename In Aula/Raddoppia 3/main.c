#include <stdlib.h>
#include <stdint.h>

void raddoppia_tre(uint32_t* x) {
	x[0] = x[0] * 2;
	x[1] = x[1] * 2;
	x[2] = x[2] * 2;
}

int main(void)
{
	uint32_t* v = malloc(3 * sizeof(uint32_t));
	v[0] = 12;
	v[1] = 59;
	v[2] = 83;
	raddoppia_tre(v);
	free(v);
	return 0;
}
