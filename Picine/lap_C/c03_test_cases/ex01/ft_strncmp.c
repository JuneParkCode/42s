/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 20:08:59 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/08 15:09:05 by sungjpar         ###   ########.fr       */
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
