/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:20:10 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/05 13:49:03 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (FAILED);
	if (run_fdf(argv[1]))
		return (SUCCESS);
	else
		return (FAILED);
}