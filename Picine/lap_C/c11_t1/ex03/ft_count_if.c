/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:38:20 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/22 21:23:59 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	count;
	int	idx_tab;

	count = 0;
	idx_tab = 0;
	while (idx_tab < length)
		count += (f(tab[idx_tab++]) != 0);
	return (count);
}
