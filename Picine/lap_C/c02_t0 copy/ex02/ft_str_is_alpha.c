/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sunjpar@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 19:04:55 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/05 19:04:57 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_is_alpha(const char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_char_is_alpha(str[i++]))
			return (0);
	}
	return (1);
}
