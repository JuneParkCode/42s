/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 19:46:31 by sungjpar          #+#    #+#             */
/*   Updated: 2022/05/29 20:41:44 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_H
# define TREE_H
# include <stddef.h>
typedef int bool;

typedef struct s_tree_node
{
	void				*content;
	struct s_tree_node	*left;
	struct s_tree_node	*right;
}	t_tree_node;

typedef struct s_tree
{
	t_tree_node	*root;
	int			(*cmp)(void *, void *);
}	t_tree;

t_tree		*make_tree(t_tree_node *root, int (*cmp)(void *, void *));
t_tree_node	*make_node(void *content);
bool		is_empty(t_tree *tree);
size_t		length(t_tree *tree);
bool		retrieve_item(t_tree *tree, void *item);
t_tree_node	*find_node(t_tree *tree, void *item);
void		insert_item(t_tree *tree, void *item);
void		delete_item(t_tree *tree, void *item);
void		reset_tree(t_tree *tree);
void		*get_next_item(t_tree *tree);

#endif
