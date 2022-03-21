/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:05:17 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/14 10:05:18 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	int	arr[3];

	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 1;
	if (index < 0)
		return (-1);
	if (index <= 2)
		return (arr[index]);
	return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}
