/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 14:06:55 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/10 19:33:48 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_color(const int z)
{
	const int	color = 0x00ff00;
	int			move;

	if (z < 0)
	{
		move = -z / 2;
		return (color >> (move * 2));
	}
	else if (z == 0)
	{
		return (0xffff00);
	}
	else
	{
		move = z / 2;
		return (color << (move * 2));
	}
}
