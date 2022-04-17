#include "array_list.h"

int	arrlst_is_full(t_arrlist *lst)
{
	return (lst -> max_size == lst -> size);
}