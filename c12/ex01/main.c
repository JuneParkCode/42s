#include <stdio.h>
#include <stdlib.h>
#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data);
t_list	*ft_create_elem(void *data)
{
	t_list	*new_list;

	new_list = malloc(sizeof(t_list));
	new_list -> data = data;
	new_list -> next = 0;
	return (new_list);
}

int	main(void)
{
	t_list	**begin_list;
	t_list	*head;
	t_list	*cur;
	char	*data1;
	char	*data2;
	char	*data3;
	char	*data4;
	
	begin_list = malloc(sizeof(t_list *));
	data1 = "abcd";
	data2 = "0003";
	data3 = "0002";
	data4 = "0001";
	head= ft_create_elem((void *) data1);
	*begin_list = head;
	ft_list_push_front(begin_list, data2);
	ft_list_push_front(begin_list, data3);
	ft_list_push_front(begin_list, data4);
	cur = *begin_list;
	while (cur)
	{
		printf("%s \n", cur -> data);
		cur = cur -> next;
	}
}
