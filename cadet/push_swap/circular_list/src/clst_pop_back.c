#include "circular_list.h"

t_dnode	*clst_pop_back(t_clist *lst)
{
	t_dnode	*node;
	t_dnode	*last_node;

	node = clst_last(lst);
	last_node = node -> prev;
	if (clst_check_alone(lst))
	{
		lst -> head = NULL;
	}
	else
	{
		lst -> head -> prev = last_node;
		last_node -> next = lst -> head;
	}
	return (node);
}
