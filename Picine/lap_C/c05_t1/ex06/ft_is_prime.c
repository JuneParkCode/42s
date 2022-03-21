/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:31:20 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/14 13:51:07 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	long long	num;

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
