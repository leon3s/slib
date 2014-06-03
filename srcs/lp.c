#include "slib.h"

size_t		print_str(const int fd, va_list arg)
{
	size_t	ret;
	char	*str;

	str = va_arg(arg, char *);
	if (!str)
		write(fd, "(null)", 6);
	else
	{
		ret = ft_strlen(str);
		write(fd, str, ret);
	}
	return (ret);
}

size_t		print_num(const int fd, va_list arg)
{
	int		num;

	num = va_arg(arg, int);
	return (putnbr_base(fd, num, DECI, 1));
}

size_t		print_ptr(const int fd, va_list arg)
{
	void	*ptr;

	ptr = va_arg(arg, void *);
	if (!ptr)
		return (write(fd, "(null)", 6));
	return (putnbr_base(fd, (ssize_t)ptr, HEXA, 0));
}
