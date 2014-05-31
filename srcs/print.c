#include "my.h"

static fprint	*init(void)
{
	fprint	*init;

	if (!(init = malloc(sizeof(*init) * 128)))
		return (0);
	init['i'] = print_num;
	init['u'] = print_num;
	init['s'] = print_str;
	init['d'] = print_num;
	init['p'] = print_ptr;
	return (init);
}

static char	flag(int n)
{
	if (n == 'i' || n == 'p' || n == 'u' || n == 's' || n == 'd')
		return (1);
	return (0);
}

ssize_t		print(const int fd, const char const *format, ...)
{
	size_t	count;
	size_t	ret;
	va_list	arg;
	fprint	*tab;

	count = -1;
	va_start(arg, format);
	if (!(tab = init()))
		return (0);
	while (format[++count])
	{
		if (format[count] == '%' && flag(format[count + 1]))
			ret += tab[((int)format[++count])](fd, arg);
		else
		{
			write(1, format + count, 1);
			ret++;
		}
	}
	va_end(arg);
	free(tab);
	return (ret);
}
