/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 22:22:35 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/21 22:22:44 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#define BUFFER_SIZE 30000

void	ft_put(char *str, unsigned int size);
int		ft_strcmp(char *s1, char *s2);

int	ft_putstdin(void)
{
	int		read_size;
	char	buffer[BUFFER_SIZE];

	read_size = read(STDIN_FILENO, buffer, BUFFER_SIZE);
	if (!read_size)
		return (1);
	while (read_size > 0)
	{
		ft_put(buffer, read_size);
		read_size = read(STDIN_FILENO, buffer, BUFFER_SIZE);
		if (!read_size)
			return (1);
	}
	return (0);
}
