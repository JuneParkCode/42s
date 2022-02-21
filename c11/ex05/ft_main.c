/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:41:24 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/22 00:46:14 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str);
int		ft_atoi(char *str);
void	ft_putnbr(long long n);
void	ft_putstr(char *str);
int		plus(int a, int b);
int		sub(int a, int b);
int		div(int a, int b);
int		mod(int a, int b);
int		mult(int a, int b);
char	*g_operators;

int	is_operator(char *str)
{
	int		idx_op;

	if (ft_strlen(str) != 1)
		return (-1);
	idx_op = 0;
	while (g_operators[idx_op])
		if (g_operators[idx_op] == str[0])
			return (idx_op);
	return (-1);
}

void	calculator(int val1, int val2, int (*f)(int, int))
{
	ft_putnbr(f(val1, val2));
	ft_putstr("\n");
}

void	do_op(int val1, int val2, int operator)
{
	int	(*arr[5])(int, int);

	arr[0] = plus;
	arr[1] = sub;
	arr[2] = mult;
	arr[3] = div;
	arr[4] = mod;
	if (operator < 0)
		ft_putstr("0\n");
	else if (operator == 2 && val2 == 0)
		ft_putstr("Stop : division by zero\n");
	else if (operator == 3 && val2 == 0)
		ft_putstr("Stop : modulo by zero\n");
	else
		calculator(val1, val2, arr[operator]);
}

int	main(int argc, char *argv[])
{
	int		val1;
	int		val2;
	int		operator;
	int		idx_op;

	g_operators = "+-*/%";
	if (argc != 4)
		return (1);
	val1 = ft_atoi(argv[1]);
	idx_op = is_operator(argv[2]);
	val2 = ft_atoi(argv[3]);
	do_op(val1, val2, idx_op);
	return (0);
}
