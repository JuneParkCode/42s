/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:33:28 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/21 18:35:39 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	*ft_map(int *tab, int length, int(*f)(int))
{
	int	idx;
	int	*res;

	idx = 0;
	res = malloc(sizeof(int) * length);
	if (!res)
		return (0);
	while (idx < length)
	{
		res[idx] = f(tab[idx]);
		++idx;
	}
	return (res);
}
