#include <stdio.h>
#include <stdlib.h>
#include "ft_list.h"

void ft_list_clear(t_list *begin_list, void (*free_fct)(void *));
void ft_strcpy(char *dest, char *src)
{
	while (*src)
		*dest++ = *src++;
	*dest = 0;
}

t_list	*ft_create_elem(void *data)
{
	t_list	*new_list;

	new_list = malloc(sizeof(t_list));
	new_list -> data = data;
	new_list -> next = 0;
	return (new_list);
}

t_list	*ft_list_last(t_list *begin_list)
{
	t_list	*cur;

	cur = begin_list;
	while (cur && cur -> next)
		cur = cur -> next;
	return (cur);
}

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*new_list;
	t_list	*last_list;
	t_list	*head;

	new_list = ft_create_elem(data);
	head = *begin_list;
	if (!head)
	{
		*begin_list = new_list;
		return ;
	}
	last_list = ft_list_last(head);
	last_list -> next = new_list;
}

void	show_list(t_list **begin_list)
{
	t_list *cur;
	
	if (!begin_list || !(*begin_list))
		return ;
	cur = *begin_list;
	printf("==SHOW LIST==\n");
	while (cur)
	{
		printf("%s \n", cur -> data);
		cur = cur -> next;
	}
}

void	free_data(void *data)
{
	free(data);
}

int	main(void)
{
	char	*data1;
	char	*data2;
	char	*data3;
	
	data1 = malloc(10);
	ft_strcpy(data1, "000000000");
	data2 = malloc(10);
	ft_strcpy(data1, "111111111");
	data3 = malloc(10);
	ft_strcpy(data1, "222222222");
	// t1
	t_list	**begin_list;
	begin_list = malloc(sizeof(t_list *));
	
	printf("T1 IN START\n");
	ft_list_push_back(begin_list, data1);
	ft_list_push_back(begin_list, data2);
	ft_list_push_back(begin_list, data3);
	printf("T1 IN END\n");
	show_list(begin_list);
	printf("T1 clear\n");
	ft_list_clear(*begin_list, free_data);
	printf("T1 clear end\n");
	*begin_list = 0;

	
	data1 = malloc(10);
	ft_strcpy(data1, "000000000");
	data2 = malloc(10);
	ft_strcpy(data1, "111111111");
	data3 = malloc(10);
	ft_strcpy(data1, "222222222");
	printf("T2 IN START\n");
	// t2
	ft_list_push_back(begin_list, data1);
	ft_list_push_back(begin_list, data2);
	ft_list_push_back(begin_list, data3);
	printf("T2 IN END\n");
	show_list(begin_list);
	
	ft_list_clear(*begin_list, free_data);
	printf("T2 clear\n");

	free(begin_list);
	system("leaks a.out > leaks_result_temp; cat leaks_result_temp | grep leaked && rm -rf leaks_result_temp");
}
