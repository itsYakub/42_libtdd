#include "libtdd.h"

/*	_strjoin - joins two string together (heap allocated)
 *
 *	Signature:
 *		char	*_strjoin(char *s1, char *s2);
 *
 *	Description:
 *		_strjoin creates a new heap-allocated string based on
 *		's1' and 's2' string. Then it copies the content of 's1'
 *		to the new string and then concat's the content of 's2' at
 *		the end of it.
 *
 *	Return:
 *		On success: newly allocated string
 *		On fail: NULL
 * */

char	*_strjoin(char *s1, char *s2) {
	char	*s;
	size_t	b1;
	size_t	b2;

	b1 = strlen(s1);
	b2 = strlen(s2);
	s = (char *) calloc(b1 + b2 + 1, sizeof(char));
	if (!s)
		return (NULL);
	strcpy(s, s1);
	strcat(s, s2);
	return (s);
}
