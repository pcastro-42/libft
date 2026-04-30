#include "libft.h"

static int	intlen(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void fill_res(char *res, int n, int len)
{
	int	i;

	i = len;
	res[i] = 0;
	i--;
	if (n == 0)
	{
		*res = '0';
		return ;
	}
	if (n < 0)
	{
		res[0] = '-';
		res[i] = '0' - (n % 10);
		n = n / 10;
		n = -n;
		i--;
	}
	while (n > 0)
	{
		res[i] = '0' + (n % 10);
		n = n / 10;
		i--;
	}
	return ;
}

char	*ft_itoa(int n)
{
	int	len;
	char	*res;

	if (n < 0)
		len = intlen(n) + 1;
	else
		len = intlen(n);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	fill_res(res, n, len);
	return (res);
}
