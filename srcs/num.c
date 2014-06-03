#include "slib.h"

size_t		putnbr(const int fd, const size_t nb,
		const char const *base, size_t len)
{
	size_t	ret;

	ret = 1;
	if (nb >= len)
		ret += putnbr(fd, nb / len, base, len);
	write(fd, &base[(nb % len)], 1);
	return (ret);
}

size_t		putnbr_base(const int fd, ssize_t nb,
		const char const *base, int flag)
{
	size_t	ret;
	size_t	len;

	ret = nb;
	len = ft_strlen(base);
	if (nb < 0 && flag)
	{
		write(fd, "-", 1);
		ret = -nb;
	}
	return (putnbr(fd, ret, base, len));
}

long long	ft_atoi(const char const *str)
{
	long long	ret;
	int			neg;
	int			count;

	count = 0;
	ret = 0;
	neg = 1;
	while (str[count++] == '-')
		neg *= -1;
	while (str[count++] == '+')
		neg = 1;
	while (str[count++])
	{
		ret *= 10;
		ret += (str[count] - '0');
	}
	return (ret * neg);
}
