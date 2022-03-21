/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:05:17 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/10 16:09:51 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	int	arr[3] = {0,1,1};
	if (index < 0)
		return (-1);
	if (index <= 2)
		return (arr[index]);
	return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}
