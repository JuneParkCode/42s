/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 12:38:58 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/09 14:05:23 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"

t_pixel	vector_projection_to_pixel(const t_vector vector, const int color)
{
	t_pixel	result_pixel;

	result_pixel.x = round(vector.x);
	result_pixel.y = round(vector.y);
	result_pixel.color = color;
	return (result_pixel);
}

