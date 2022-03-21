/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sunjpar@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 19:06:12 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/06 14:50:28 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(const char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		++i;
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] != '\0' && i < (size - 1))
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}
