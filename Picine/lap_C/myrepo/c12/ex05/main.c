#include <stdio.h>
#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs);

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
	char	*strs[] = {"1", "2", "3", "4", "5","6"};
	char	*strs2[] = {};
	t_list	*l1;
	t_list	*l2;
	t_list	*cur;

	l1 = ft_list_push_strs(6, strs);
	cur = l1;
	printf("==========l1==========\n");
	while (cur)
	{
		printf("%s \n", cur -> data);
		cur = cur -> next;
	}
	l2 = ft_list_push_strs(0, strs2);
	cur = l2;
	printf("==========l2==========\n");
	while (cur)
	{
		printf("%s \n", cur -> data);
		cur = cur -> next;
	}
	l2 = ft_list_push_strs(1, strs2); // err case
	cur = l2;
	printf("==========err==========\n");
	while (cur)
	{
		printf("%s \n", cur -> data);
		cur = cur -> next;
	}
}
