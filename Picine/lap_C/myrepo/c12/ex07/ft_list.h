/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 23:15:47 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/23 00:19:36 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H
typedef struct	s_list
{
	void			*data;
	struct s_list	*next;
}				t_list;
t_list	*ft_create_elem(void *data);
#endif
