/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:46:29 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/21 10:35:19 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_number(const char c)
{
	return ('0' <= c && c <= '9');
}

int	ft_atoi(char *str)
{
	int	result;
	int	i;

	i = 0;
	result = 0;
	while (ft_is_number(str[i]))
	{
		result *= 10;
		result += str[i] - '0';
		++i;
	}
	return (result);
}
