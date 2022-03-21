/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 00:41:15 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/23 18:39:56 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int	i;
	int	j;
	int	n;

	n = 0;
	while (tab[n])
		++n;
	i = n - 1;
	while (i > 0)
	{
		j = 0;
		while (j < i)
		{
			if (cmp(tab[j], tab[j + 1]) > 0)
				swap(&tab[j], &tab[j + 1]);
			++j;
		}
		--i;
	}
}
