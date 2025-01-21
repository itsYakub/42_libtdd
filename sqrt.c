#include "libtdd.h"

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
