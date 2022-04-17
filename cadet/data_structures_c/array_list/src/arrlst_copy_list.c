#include "array_list.h"

int	arrlst_copy_list(t_arrlist *dest, t_arrlist *src)
{
	ssize_t	src_pos;
	ssize_t	end_pos;

	if (dest -> max_size < src -> max_size)
		return (FUNC_ERR);
	arrlst_clear(dest);
	if (arrlst_is_empty(src))
		return (SUCCESS);
	src_pos = src -> front;
	end_pos = (src -> rear + 1) % src -> max_size;
	while (src_pos != end_pos)
	{
		arrlst_push_back(dest, (src -> items)[src_pos]);
		src_pos = (src_pos + 1) % src -> max_size;
	}
	return (SUCCESS);
}