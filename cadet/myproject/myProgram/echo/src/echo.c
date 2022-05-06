/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 19:36:36 by sungjpar          #+#    #+#             */
/*   Updated: 2022/05/06 19:53:20 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "echo.h"

int	echo(int argc, char *argv[])
{
	int	arg_n;

	arg_n = 1;
	if (argc < 2)
	{
		ft_putendl_fd("", 1);
		return (SUCCESS);
	}
	while (arg_n < argc - 1)
	{
		ft_putstr_fd(argv[arg_n], 1);
		ft_putchar_fd(' ', 1);
		++arg_n;
	}
	ft_putendl_fd(argv[arg_n], 1);
	return (SUCCESS);
}
