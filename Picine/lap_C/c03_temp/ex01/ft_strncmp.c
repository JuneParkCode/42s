/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sunjpar@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 20:08:59 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/07 18:10:30 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_return_cmp(int n)
{
	if (n < 0)
		return (-1);
	else if (n == 0)
		return (0);
	else
		return (1);
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] && s2[i] && i < n)
	{
		if (s1[i] != s2[i])
			return (ft_return_cmp(s1[i] - s2[i]));
		++i;
	}
	return (ft_return_cmp(s1[i] - s2[i]));
}
