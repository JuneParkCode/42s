/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:44:44 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/19 10:42:43 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

void	ft_strcpy(char *dest, char *src)
{
	while (*src)
		*(dest++) = *(src++);
	*dest = 0;
}

t_stock_str	ft_stock(int size, char *str, char *copy)
{
	t_stock_str	bank;

	bank.size = size;
	bank.str = str;
	bank.copy = copy;
	return (bank);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*result;
	char		*copy;
	int			idx;
	int			len_str;

	if (ac < 0 || !av)
		return (0);
	result = malloc(sizeof(t_stock_str) * (ac + 1));
	if (!result)
		return (0);
	idx = 0;
	while (ac && idx < ac)
	{
		len_str = ft_strlen(av[idx]);
		copy = malloc(sizeof(char) * (len_str + 1));
		if (!copy)
			return (0);
		ft_strcpy(copy, av[idx]);
		result[idx] = ft_stock(len_str, av[idx], copy);
		++idx;
	}
	result[idx] = ft_stock(0, 0, 0);
	return (result);
}
