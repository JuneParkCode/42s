#include <stdio.h>
#include <stdlib.h>
#include "ft_list.h"

//int		ft_list_size(t_list *begin_list);
void	ft_list_push_front(t_list **begin_list, void *data);
t_list	*ft_create_elem(void *data);
t_list	*ft_list_last(t_list *begin_list);
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
	// null test !!
	//*begin_list = 0;
	while (cur)
	{
		printf("%s \n", cur -> data);
		cur = cur -> next;
	}
	//printf("size : %d\n", ft_list_size(*begin_list));
	printf("last list : %s\n", ft_list_last(*begin_list) -> data);
}
