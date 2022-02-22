/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 16:31:08 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/20 15:11:55 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_puterr(char *str)
{
	while (*str)
		write(2, str++, 1);
}

void	ft_put(char *str, unsigned int size)
{
	unsigned int	idx;

	idx = 0;
	while (idx < size)
		write(1, &str[idx++], 1);
}

void	ft_msg(char *file_name, int err_code, char *bs_name)
{
	ft_puterr(bs_name);
	ft_puterr(": ");
	ft_puterr(file_name);
	ft_puterr(": ");
	ft_puterr(strerror(err_code));
	ft_puterr("\n");
}

int	ft_strcmp(char *s1, char *s2)
{
	int				i;
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
