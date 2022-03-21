/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:45:51 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/08 16:02:37 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(const char *str)
{
	int	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	len_dest;
	unsigned int	len_src;
	unsigned int	i_dest;
	unsigned int	i_src;

	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	i_dest = len_dest;
	i_src = 0;
	if (size == 0)
		return (size + len_src);
	while (i_src < len_src && i_dest < size - 1)
		dest[i_dest++] = src[i_src++];
	dest[i_dest] = 0;
	if (len_dest > size)
		return (size + len_src);
	return (len_dest + len_src);
}
