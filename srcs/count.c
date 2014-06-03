#include "slib.h"

size_t		count_num(const ssize_t val)
{
	ssize_t	tmp;
	int		count;

	tmp = val;
	while (tmp /= 10)
		count++;
	return (count);
}

size_t		ft_strlen(const char const *str)
{
	size_t	count;

	count = -1;
	while (str[++count])
		;
	return (count);
}
