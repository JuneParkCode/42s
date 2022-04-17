/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_list.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:03:58 by sungjpar          #+#    #+#             */
/*   Updated: 2022/04/15 18:36:04 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CIRCULAR_LIST_H
# define CIRCULAR_LIST_H

# include <stddef.h>
/* node for double linked link struct definition */
typedef struct	s_dnode
{
	void			*content;
	struct s_dnode	*prev;
	struct s_dnode	*next;
}	t_dnode;

typedef struct	s_clist
{
	t_dnode	*head;
}	t_clist;

/* insert node */
t_clist	clst_insert(t_clist *lst, t_dnode *insert_point, t_dnode *node); 

/* add back */
void	clst_add_back(t_clist *lst, t_dnode *node);

/* add front */
void	clst_add_front(t_clist *lst, t_dnode *node);

/* make new node */
t_dnode	*clst_get_new_node(void *content);

/* delete node */
void	clst_del_node(t_dnode *node, void (*f_del)(void *));

/* clear list */
void	clst_clear(t_clist *lst, void(*f_del)(void *));

/* find node that matches content */
t_dnode *clst_find_node(t_clist *lst, void *content, int (*f_cmp)(void *, void *));

/* swap node */
void	clst_swap_node(t_clist *lst, t_dnode *node_a, t_dnode *node_b);

/* check is empty list */
int		clst_is_empty(t_clist *lst);

/* get list length */
size_t	clst_get_length(t_clist *lst);

/* merge list and return new merged list */
t_clist	*clst_merge_list(t_clist *front, t_clist *back);

/* get last node of list */
t_dnode	*clst_last(t_clist *lst);

/* print list */
void	clst_print_list(t_clist *lst, void (*f_print)(void *));

/* pop front */
t_dnode	*clst_pop_front(t_clist *lst);

/* pop back */
t_dnode	*clst_pop_back(t_clist *lst);

/* check list length is 1 or not*/
int		clst_check_alone(t_clist *lst);

/* print functions... */
void	f_print_nbr(void *content);
void	f_print_str(void *content);
void	f_print_chr(void *content);

/* ptr compare functions */
int		f_ptr_strcmp(void *s1, void *s2);
int		f_ptr_intcmp(void *s1, void *s2);
int		f_ptr_llcmp(void *s1, void *s2);

#endif 
