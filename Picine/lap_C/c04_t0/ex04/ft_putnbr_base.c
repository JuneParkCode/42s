/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:46:35 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/10 08:45:33 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(const char *str)
{
	int	length;

	length = 0;
	while (str[length])
		++length;
	return (length);
}

int	ft_valid_base(const char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (str[i] == '-' || str[i] == '+')
				return (0);
			if (str[i] == str[j])
				return (0);
			++j;
		}
		++i;
	}
	return (i > 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	n;
	unsigned int	len_base;

	len_base = ft_strlen(base);
	if (!ft_valid_base(base))
		return ;
	if (nbr < 0)
	{
		n = -nbr;
		write(1, "-", 1);
	}
	else
		n = nbr;
	if (n >= len_base)
		ft_putnbr_base(n / len_base, base);
	write(1, &base[n % len_base], 1);
}
