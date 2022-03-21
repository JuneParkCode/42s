/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:31:20 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/14 10:57:41 by sungjpar         ###   ########.fr       */
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
	while (num <= sqrt)
	{
		if (nb % num == 0)
			return (0);
		++num;
	}
	return ((nb % num) != 0);
}
