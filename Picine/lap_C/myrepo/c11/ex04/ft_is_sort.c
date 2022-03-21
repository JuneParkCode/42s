/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 00:00:58 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/22 00:47:23 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	idx_tab;
	int	positive;
	int	negative;

	idx_tab = 0;
	positive = 0;
	negative = 0;
	while (idx_tab < length - 1)
	{
		positive += (f(tab[idx_tab], tab[idx_tab + 1]) <= 0);
		negative += (f(tab[idx_tab], tab[idx_tab + 1]) >= 0);
		++idx_tab;
	}
	return (positive == (length - 1) || negative == (length - 1));
}
