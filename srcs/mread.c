#include "slib.h"

static char	*reverse_list(t_list *s)
{
	size_t	count;
	ssize_t	len;
	t_list	*tmp;
	char	*buff;

	len = 0;
	count = -1;
	tmp = s;
	while (tmp)
	{
		len += tmp->len;
		tmp = tmp->next;
	}
	if (!(buff = malloc(sizeof(*buff) * (len + 1))))
		return (0);
	tmp = s;
	while (tmp)
	{
		len = -1;
		while (++len < tmp->len)
			buff[++count] = tmp->str[len];
		tmp = tmp->next;
	}
	buff[count] = 0;
	return (buff);
}

char	*mread(const int fd)
{
	t_list	*s;
	t_list	*tmp;

	if (!(tmp = malloc(sizeof(*tmp))))
		return (0);
	s = tmp;
	tmp->len = 0;
	while (((tmp->len = read(fd, tmp->str, BSIZE)) > 0))
	{
		if (!(tmp->next = malloc(sizeof(*tmp))))
			return (0);
		tmp = tmp->next;
	}
	tmp->next = NULL;
	if (tmp->len == -1)
		return (0);
	return (reverse_list(s));
}
