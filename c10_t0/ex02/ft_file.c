/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 13:51:19 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/21 22:23:33 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE 20000

long long	get_file_size(char *file_name)
{
	long long	fd;
	long long	size;
	long long	read_size;
	char		*buffer[BUF_SIZE];

	fd = open(file_name, O_RDONLY);
	read_size = 1;
	size = 0;
	while (1)
	{
		read_size = read(fd, buffer, BUF_SIZE);
		if (read_size <= 0)
			break ;
		size += read_size;
	}
	close(fd);
	return (size);
}
