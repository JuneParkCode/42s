#include "circular_list.h"

int	clst_check_alone(t_clist *lst)
{
	return (lst -> head -> prev == lst -> head);
}
