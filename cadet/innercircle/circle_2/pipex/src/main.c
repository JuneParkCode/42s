/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 08:51:07 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/20 19:24:01 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "pipex.h"

int	main(const int argc, char *argv[])
{
	check_valid_argument(argc);
	do_commands(argc, argv);
	return (SUCCESS);
}
