#include "libtdd.h"

/*	_memmove - copy the source to destination (including overlaps)
 *
 *	Signature:
 *		void	*_memmove(void *dst, void *src, size_t c);
 *
 *	Description:
 *		_memmove copies 'c' bytes of memory block 'src' into the
 *		'dst' memory block. THis function accounts for overlap in memory
 *		(check "Example").
 *
 *	Return:
 *		On success: memory block of copied bytes
 *
 *	Example:
 *		char	*src;
 *		char	dst[16];
 *		
 *		// abstract scenario ...
 *		memset(dst, "Hello, world!", 14);
 *		src = dst + 1; // <-- overlap
 *
 *		// now let's copy some bytes from src to dst
 *		dst = _memmove(dst, src, 5);
 * */

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
