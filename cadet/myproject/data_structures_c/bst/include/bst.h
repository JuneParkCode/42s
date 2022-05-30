/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 19:46:31 by sungjpar          #+#    #+#             */
/*   Updated: 2022/05/30 10:28:51 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BST_H
# define BST_H
# include <stddef.h>
# include <stdbool.h>

typedef struct s_bst_node
{
	void				*content;
	struct s_bst_node	*left;
	struct s_bst_node	*right;
}	t_bst_node;

typedef struct s_bst
{
	t_bst_node	*root;
	int			(*cmp)(void *, void *);
}	t_bst;

t_bst		*bst_new_tree(t_bst_node *root, int (*cmp)(void *, void *));
t_bst_node	*bst_make_node(void *content);
bool		bst_is_empty(t_bst *tree);
size_t		bst_get_length(t_bst *tree);
bool		bst_retrieve_item(t_bst *tree, void *item);
t_bst_node	*bst_find_node(t_bst *tree, void *item);
void		bst_insert(t_bst *tree, void *item);
void		bst_delete_item(t_bst *tree, void *item);
void		bst_reset_tree(t_bst *tree);
void		*bst_get_next_item(t_bst *tree);

#endif
