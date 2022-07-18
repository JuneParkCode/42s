/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 08:51:07 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/18 11:11:59 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "pipex.h"

int	main(const int argc, char *argv[])
{
	if (is_valid_argument(argc, argv) == FALSE)
	{
		perror("Invalid arguments");
		return (FAILED);
	}
	else
		return (run_pipex(argc, argv));
}
