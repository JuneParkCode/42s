
#include <stdlib.h>
#include "circular_list.h"

void	clst_del_node(t_dnode *node, void(*f_del)(void *))
{
	f_del(node -> content);
	free(node);
}
