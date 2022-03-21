/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sunjpar@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 19:05:42 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/05 19:05:44 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_is_printable(const char c)
{
	return (32 <= c && c < 127);
}

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_char_is_printable(str[i]))
			return (0);
		++i;
	}
	return (1);
}
