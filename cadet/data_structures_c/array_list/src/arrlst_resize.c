#include <stdlib.h>
#include "array_list.h"

ssize_t	arrlst_resize(t_arrlist **lst, ssize_t size)
{
	t_arrlist	*new_lst;

	if (size < (*lst) -> size)
		return (NOT_FOUND);
	else if (size == (*lst) -> size)
		return (size);
	else
	{
		new_lst = arrlst_new_list(size);
		if (new_lst == NULL)
			return (NOT_FOUND);
		arrlst_push_back(new_lst, arrlst_pop_front(*lst));
		free((*lst) -> items);
		free(*lst);
		*lst = new_lst;		
	}
	return (size);
}