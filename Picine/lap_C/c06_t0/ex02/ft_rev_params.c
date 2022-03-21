/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:07:37 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/14 10:19:28 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putstr(const char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	main(int argc, char *argv[])
{
	int	i;

	if (argc <= 0)
		return (0);
	i = argc - 1;
	while (i > 0)
	{
		ft_putstr(argv[i]);
		ft_putstr("\n");
		--i;
	}
	return (0);
}
