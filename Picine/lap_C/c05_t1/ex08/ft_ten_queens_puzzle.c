/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:55:10 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/14 14:36:41 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_arr(int *arr, unsigned int n)
{
	unsigned int	i;
	char			c;

	i = 0;
	while (i < n)
	{
		c = '0' + arr[i];
		write(1, &c, 1);
		++i;
	}
	write(1, "\n", 1);
}

int	ft_is_valid_position(int cur_idx, int cur_pos, int *arr)
{
	int	i;

	i = 0;
	while (i < cur_idx)
	{
		if (cur_pos == arr[i])
			return (0);
		if (cur_pos == (arr[i] + cur_idx - i)
			|| cur_pos == (arr[i] - (cur_idx - i)))
			return (0);
		i++;
	}
	return (1);
}

void	ft_n_queens_puzzle(int cur_idx, int n, int *arr, int *result)
{
	int	cur_pos;

	cur_pos = 0;
	if (cur_idx == n)
	{
		ft_print_arr(arr, n);
		*result += 1;
		return ;
	}
	while (cur_pos < n)
	{
		if (ft_is_valid_position(cur_idx, cur_pos, arr))
		{
			arr[cur_idx] = cur_pos;
			ft_n_queens_puzzle(cur_idx + 1, n, arr, result);
		}
		++cur_pos;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	result;
	int	arr[100];

	result = 0;
	ft_n_queens_puzzle(0, 10, arr, &result);
	return (result);
}
