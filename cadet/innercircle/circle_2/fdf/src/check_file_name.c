/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:11:17 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/08 18:26:02 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

t_bool	is_valid_file_name(const char *file_name)
{
	const char	*valid_extension = ".fdf";
	const char	*extension_pos = ft_strrchr(file_name, '.');

	if (extension_pos == NULL)
		return (FALSE);
	return (ft_strncmp(extension_pos, valid_extension, -1) == 0);
}
