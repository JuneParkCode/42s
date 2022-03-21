/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_funcs2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 10:51:19 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/21 17:12:40 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdio.h>

void	ft_putstr(char *str);
void	ft_puterr(char *str);
char	*g_bs_name;

void	put_lines(char *str)
{
	long long	idx;

	idx = 0;
	while (str[idx] != '\n')
		write(1, &str[idx++], 1);
	write(1, "\n", 1);
}

void	put_file_name(char *file_name, int flag)
{
	if (flag)
		ft_putstr("\n");
	ft_putstr("==> ");
	ft_putstr(file_name);
	ft_putstr(" <==\n");
}

void	put_err_offset(char *str)
{
	ft_puterr(g_bs_name);
	ft_puterr(": illegal offset -- ");
	ft_puterr(str);
	ft_puterr("\n");
}
