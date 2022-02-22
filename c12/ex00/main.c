#include "ft_list.h"
#include <stdio.h>

t_list	*ft_create_elem(void *data);

int	main(void)
{
	void	*data;
	t_list	*list;

	data = "abcd";
	list = ft_create_elem(data);
	printf("%s", list -> data);
	return (0);
}
