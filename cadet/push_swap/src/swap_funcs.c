
#include "stack.h"

int	swap_node(t_stack *_stack)
{
	t_clist	*lst;
	t_dnode	*node_a;
	t_dnode	*node_b;

	if (_stack == NULL || _stack -> lst == NULL)
		return (1);
	lst = _stack -> lst;
	if (clst_get_length(lst) <= 0)
		return (0);
	node_a = lst -> head;
	node_b = node_a -> next;
	clst_swap_node(lst, node_a, node_b);
	return (0);
}

int	swap_a(t_stack *stack_a)
{
	return (swap_node(stack_a));
}

int	swap_b(t_stack *stack_b)
{
	return (swap_node(stack_b));
}

int	swap_ab(t_stack *stack_a, t_stack *stack_b)
{
	return (!swap_node(stack_a) && !swap_node(stack_b));
}