/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:21:59 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/20 16:22:01 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[])
{
	if (is_valid_argument(argc) == FALSE)
		return (1);
	do_commands(argc, argv);
	return (SUCCESS);
}
