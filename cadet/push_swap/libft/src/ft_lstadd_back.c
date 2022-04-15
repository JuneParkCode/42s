/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 18:29:23 by sungjpar          #+#    #+#             */
/*   Updated: 2022/03/13 19:30:04 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Function		:	ft_lstbadd_back
 * Description	:	Adds the element ’new’ at the end of the list.
 * Param		
 * 		lst		:	The address of a pointer to the first link of a list.
 * 		new		:	The address of a pointer to the element to be added to 
 * 					the list.
 * Return Value	:	NONE
 */

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_node;

	if (lst == NULL)
		return ;
	last_node = ft_lstlast(*lst);
	if (last_node == NULL)
		*lst = new;
	else
		last_node -> next = new;
}
