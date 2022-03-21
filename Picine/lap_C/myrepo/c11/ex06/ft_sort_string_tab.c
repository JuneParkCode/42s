/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 00:34:27 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/22 00:45:20 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	ft_strcmp(char *s1, char *s2)
{
	long long		i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	while (str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		++i;
	}
	return (str1[i] - str2[i]);
}

void	ft_sort_string_tab(char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		j = i + 1;
		while (tab[i] && tab[j])
		{
			if (ft_strcmp(tab[i], tab[j]) > 0)
				swap(&tab[i], &tab[j]);
			++j;
		}
		++i;
	}
}
