/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argument_functions_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 09:50:04 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/20 21:17:54 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "pipex_bonus.h"
#include "libft.h"

t_bool	check_valid_argument(const int argc)
{
	if (argc < 5)
	{
		errno = EINVAL;
		put_error_and_exit();
	}
	return (TRUE);
}

t_bool	is_heredoc_mode(int argc, char **argv)
{
	if (ft_strncmp("here_doc", argv[1], -1) == 0)
	{
		if (argc < 6)
		{
			errno = EINVAL;
			put_error_and_exit();
			return (FALSE);
		}
		else
		{
			return (TRUE);
		}
	}
	else
		return (FALSE);
}
