#include "libtdd.h"

void	*_memmove(void *dst, void *src, size_t c) {
	unsigned char	*dcpy;
	unsigned char	*scpy;

	if (dst < src) {
		dcpy = dst;
		scpy = src;
		while (c--) {
			*dcpy++ = *scpy++;
		}
	}
	else {
		dcpy = dst + c - 1;
		scpy = src + c - 1;
		while (c--) {
			*dcpy-- = *scpy--;
		}
	}
	return (dst);
}
