/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:35:53 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/22 21:23:17 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_any(char **tab, int (*f)(char*))
{
	int	idx_tab;

	idx_tab = 0;
	if (!tab)
		return (0);
	while (tab[idx_tab])
	{
		if (f(tab[idx_tab++]) != 0)
			return (1);
	}
	return (0);
}
