/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argument_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 09:50:04 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/20 19:26:00 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "pipex.h"

t_bool	check_valid_argument(const int argc)
{
	if (argc != 5)
	{
		errno = EINVAL;
		put_error_and_exit();
	}
	return (TRUE);
}
