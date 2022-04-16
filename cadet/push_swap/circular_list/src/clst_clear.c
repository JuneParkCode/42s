
#include "circular_list.h"

void	clst_clear(t_clist *lst, void (*f_del)(void *))
{
	t_dnode	*last_node;
	t_dnode	*node;
	t_dnode	*next_node;
	
	last_node = clst_last(lst);
	node = lst -> head;
	if (last_node == node)
	{
		clst_del_node(node, f_del);
		lst -> head = NULL;
		return ;
	}
	while (node -> next != lst -> head)
	{
		next_node = node -> next;
		clst_del_node(node, f_del);
		node = next_node;
	}
	lst -> head = NULL;
}
