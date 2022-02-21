/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 19:03:11 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/21 22:21:27 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

void	ft_put(char *str, unsigned long long size)
{
	unsigned long long	idx;

	idx = 0;
	while (idx < size)
		write(1, &str[idx++], 1);
}

void	ft_puterr(char *str)
{
	while (*str)
		write(2, str++, 1);
}

int	ft_check_input_error(int argc)
{
	if (argc <= 1)
	{
		ft_puterr("File name missing.\n");
		return (1);
	}
	if (argc > 2)
	{
		ft_puterr("Too many arguments.\n");
		return (2);
	}
	return (0);
}

int	ft_display_file(char *file_name)
{
	char	buffer[200];
	int		fd;
	int		read_size;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		ft_puterr("Cannot read file.\n");
		return (2);
	}
	read_size = 1;
	while (read_size > 0)
	{
		read_size = read(fd, buffer, 200);
		if (read_size < 0)
			break ;
		ft_put(buffer, read_size);
	}
	close(fd);
	return (0);
}

int	main(int argc, char *argv[])
{
	if (ft_check_input_error(argc))
		return (-1);
	if (ft_display_file(argv[1]))
		return (-2);
	return (0);
}
