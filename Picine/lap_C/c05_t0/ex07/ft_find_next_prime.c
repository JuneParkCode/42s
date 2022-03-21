/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:42:47 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/14 10:58:21 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	n;

	n = 0;
	if (nb <= 0)
		return (0);
	while (n <= 46340 && n * n < nb)
		++n;
	return (n * n == nb);
}

int	ft_is_prime(int nb)
{
	int	num;
	int	sqrt;

	sqrt = ft_sqrt(nb);
	if (nb <= 1)
		return (0);
	if (nb == 2)
		return (1);
	num = 2;
	while (num * num < nb)
	{
		if (nb % num == 0)
			return (0);
		++num;
	}
	return ((nb % num) != 0);
}

int	ft_find_next_prime(int nb)
{
	while (!ft_is_prime(nb))
		nb++;
	return (nb);
}
