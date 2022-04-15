#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "circular_list.h"

int	main(void)
{
	t_clist	lst;
	t_dnode	*node;

	lst.head = NULL;
	for (int i = 0; i < 10; ++i)
	{
		int	*x;
		x = malloc(sizeof(int));
		*x = i;
		node = clst_get_new_node(x);
		clst_addback(&lst, node); 
	}
	clst_print_list(&lst);
}
