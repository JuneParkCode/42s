/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_arrlst.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:07:40 by sungjpar          #+#    #+#             */
/*   Updated: 2022/04/18 15:08:10 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_ARRLST_H
# define STACK_ARRLST_H
# include "array_list.h"

typedef struct s_stack
{
	t_arrlist	*lst;
	ssize_t		*top;
	size_t		size;
	size_t		max_size;
}				t_stack;

/* make new stack */
t_stack	*stack_new(size_t size);

/* push item functions */
int		stack_push(t_stack *_stack, t_item item);

/* pop item function */
t_item	stack_pop(t_stack *_stack);

/* find item function */
ssize_t	stack_find_item(t_stack *_stack, t_item item, \
		int (*cmp)(t_item, t_item));

/* get length of list */
int		stack_get_size(t_stack *_stack);

/* check list is full */
int		stack_is_full(t_stack *_stack);

/* check list is empty */
int		stack_is_empty(t_stack *_stack);

/* change max_size of list*/
ssize_t	stack_resize(t_stack *_stack, ssize_t size);

/* copy list */
int		stack_copy_stack(t_stack *dest, t_stack *src);

/* swap item function */
int		stack_swap(t_stack *_stack, t_item item_a, t_item item_b, \
		int (*cmp)(t_item, t_item));

/* swap top, top + 1 */
int		stack_swap_top(t_stack *_stack, int (*cmp)(t_item, t_item));

/* clear list */
void	stack_clear(t_stack *_stack);
#endif
