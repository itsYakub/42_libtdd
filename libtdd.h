#ifndef LIBTDD_H
# define LIBTDD_H

# include <stdlib.h>
# include <string.h>
# include <stddef.h>

char	*_strjoin(char *s1, char *s2);
char	**_split(char *s, char delim);
void	*_memmove(void *dst, void *src, size_t c);
int		_sqrt(int n);

#endif /* LIBTDD_H */
