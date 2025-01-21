#include "libtdd.h"

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
