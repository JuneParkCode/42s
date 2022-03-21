/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:28:46 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/10 16:29:47 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int ft_sqrt(int nb)
{
	int	n;

	n = 0;
	if (nb <= 0)
		return (0);
	while (n * n < nb)
		++n;
	return (n * n == nb);
}

int	ft_find_next_prime(int nb)
{
	while (!ft_sqrt(nb))
		++nb;
	return (nb);
}
