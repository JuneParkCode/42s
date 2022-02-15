#include <stdlib.h>

int	ft_atoi_base(char *str, char *base);
int	ft_valid_base(char *str);

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length])
		++length;
	return (length);
}

void	ft_converter(int nbr, char *base_to, char *result, int idx)
{
	long long	n;
	long long	len_base;

	len_base = ft_strlen(base_to);
	if (!ft_valid_base(base_to))
		return ;
	if (nbr < 0)
	{
		n = -nbr;
		result[0] = '-';
	}
	else
		n = nbr;
	if (n >= len_base)
		ft_converter(n / len_base, base_to, result, idx - 1);
	result[idx] = base_to[n % len_base];
}

int ft_num_len(int nbr, char *base)
{
	int			len_base;
	int			len_num;
	long long	n;

	if (nbr == 0)
		return (1);
	len_base = 0;
	len_num = 0;
	n = nbr;
	if (n < 0)
		n = -nbr;
	while (base[len_base])
		++len_base;
	while (n > 0)
	{
		n /= len_base;
		len_num++;
	}
	return (len_num);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char		*result;
	long long	n;
	int			len_num;
	int			size;

	if (!ft_valid_base(base_from) || !ft_valid_base(base_to))
		return (0);
	n = ft_atoi_base(nbr, base_from);
	len_num = ft_num_len(n, base_to);
	size = (len_num + 1) + (n < 0);
	result = (char *) malloc(sizeof(char) * (size));
	ft_converter(n, base_to, result, size - 2);
	result[size - 1] = 0;
	return (result);
}