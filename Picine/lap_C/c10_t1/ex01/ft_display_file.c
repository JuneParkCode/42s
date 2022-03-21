/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 19:03:11 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/22 19:24:58 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

# define BUFFER_SIZE 30000

void	ft_puterr(char *str, int errno);
void	ft_put(char *str, unsigned int size);
void	ft_msg(char *file_name, int err_code, char *bs_name);

int	ft_check_input_error(int argc)
{
	if (argc <= 1)
	{
		ft_puterr(strerror(errno));
		return (1);
	}
	if (argc > 2)
	{
		ft_puterr(strerror(errno));
		return (2);
	}
	return (0);
}

int	ft_display_file(char *file_name, char *bs_name)
{
	char	buffer[BUFFER_SIZE];
	int		fd;
	int		read_size;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		ft_msg(file_name, errno, bs_name);
		return (errno);
	}
	while (1)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size == 0)
			break ;
		if (read_size < 0)
		{
			ft_msg(file_name, errno, bs_name);
			break ;
		}
		ft_put(buffer, read_size);
	}
	close(fd);
	return (0);
}
