
#include "circular_list.h"
#include "libft.h"

t_dnode *clst_find_node(t_clist *lst, void *content, int (*f_cmp)(void *, void *))
{
	t_dnode	*node;

	node = lst -> head;
	if (f_cmp(content, node -> content) == 0)
		return (node);
	while (node -> next != lst -> head)
	{
		node = node -> next;
		if (f_cmp(content, node -> content) == 0)
			return (node);
	}
	return (NULL);
}
