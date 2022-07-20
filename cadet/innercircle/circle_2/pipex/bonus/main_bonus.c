/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 08:51:07 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/20 20:03:22 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "pipex_bonus.h"

int	main(const int argc, char *argv[])
{
	check_valid_argument(argc);
	if (is_heredoc_mode(argc, argv) == TRUE)
		do_heredoc_mode(argc, argv);
	else
		do_commands(argc, argv);
	return (SUCCESS);
}
