#include "array_list.h"

int	arrlst_swap(t_arrlist *lst, t_item item_a, t_item item_b, int(*cmp)(t_item, t_item))
{
	ssize_t	pos_a;
	ssize_t	pos_b;

	pos_a = arrlst_find_item(lst, item_a, cmp);
	pos_b = arrlst_find_item(lst, item_b, cmp);
	if (pos_a == -1 || pos_b == -1)
		return (FUNC_ERR);
	lst -> items[pos_a] = item_b;
	lst -> items[pos_b] = item_a;
	return (SUCCESS);
}