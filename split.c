#include "libtdd.h"

static size_t	__word_count(char *s, char delim);

char	**_split(char *s, char delim) {
	char	**arr;
	size_t	toklen;
	size_t	iter;

	arr = (char **) calloc(__word_count(s, delim) + 1, sizeof(char *));
	if (!arr) {
		return (NULL);
	}
	iter = 0;
	while (*s) {
		while (*s == delim)
			s++;
		if (*s)
		{
			if (strchr(s, delim))
				toklen = strchr(s, delim) - s;
			else if (!strchr(s, delim))
				toklen = strlen(s);
			arr[iter] = (char *) calloc(toklen + 1, sizeof(char));
			strncpy(arr[iter], s, toklen);
			iter++;
			s += toklen;
		}
	}
	return (arr);
}

static size_t	__word_count(char *s, char delim) {
	size_t	c;

	if (!s || !(*s)) {
		return (0);
	}
	c = 1;
	while (*s) {
		if (*s != delim) {
			c++;
			while (*s != delim) {
				s++;
			}
		}
		if (*s) {
			s++;
		}
	}
	return (c);
}
