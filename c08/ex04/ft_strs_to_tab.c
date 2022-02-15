
#include "ft_stock_str.h"
#include <stdlib.h>
int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while(str[length])
		length++;
	return (length);
}

void	ft_strcpy(char *dest, char *src)
{
	while (*src)
		*(dest++) = *(src++);
	*dest = 0;
}

struct s_stock_str ft_stock(int size, char *str, char *copy)
{
	s_stock_str bank;

	bank.size = size;
	bank.str = str;
	bank.copy = copy;
	return (bank);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str *result;
	struct s_stock_str last;
	char				*copy;
	int					idx;
	int					len_str;

	if (!ac || !av)
		return (0);
	result = (struct s_stock_str *)\
		malloc(sizeof(struct s_stock_str) * (ac + 1));
	idx = 0;
	while (idx < ac)
	{
		len_str = ft_strlen(av[idx]);
		copy = (char *) malloc(sizeof(char) * (len_str + 1));
		ft_strcpy(copy, av[idx]);
		result[idx] = ft_stock(len_str, av[idx], copy);
		++idx;
	}
	last.size = 0;
	last.str = 0;
	last.copy = 0;
	result[idx] = last;
	return (result);
}