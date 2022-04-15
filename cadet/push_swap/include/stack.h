/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:52:10 by sungjpar          #+#    #+#             */
/*   Updated: 2022/04/15 16:03:48 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H
# define FT_STACK_H

# include <stddef.h>
# include "circular_list.h"

/* boolean type definition */
typedef int	t_bool;

/* stack elem type definition */
typedef int	t_elem;


/* stack struct definition */
typedef struct s_stack
{
	t_clist	*top;
	size_t	size;
	t_bool	(*cmp)();
}				t_stack

#endif
