#include "libtdd.h"

/*	_sqrt - get the square root of the number
 *
 *	Signature:
 *		int	_sqrt(int n);
 *
 *	Description:
 *		_sqrt returns, if possible, the square root of the integer 'n'.
 *		Otherwise it returns 0.
 *
 *	Return:
 *		On success: an integer result of a square root 
 *		On fail: 0
 * */

int	_sqrt(int n) {
	int	n0;

	if (n <= 0)
		return (0);
	n0 = 1;
	while (n0 * n0 <= n)
	{
		if (n0 * n0 == n)
			return (n0);
		n0++;
	}
	return (0);
}
