/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 19:03:11 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/19 16:33:02 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#define BUFFER_SIZE 30000

void	ft_putstr(char *str);
void	ft_put(char *str, unsigned int size);
void	ft_msg(char *file_name, int err_code);

/*
 *  ft_check_input_error
 *  Description		:	function checks input error
 *	return value	:	1	: Missing file name
 *						2	: Too many arguments
 *						0	: Success
 */
int	ft_check_input_error(int argc)
{
	if (argc <= 1)
	{
		ft_putstr(strerror(errno));
		return (1);
	}
	if (argc > 2)
	{
		ft_putstr(strerror(errno));
		return (2);
	}
	return (0);
}

/*
 *	ft_display_file
 *	Description		:	function displays content of file
 *	return value	: 0	: success
 *					  1 : fail (arg error)
 *					  2 : fail (file open error)
 */
int	ft_display_file(char *file_name)
{
	char	buffer[BUFFER_SIZE];
	int		fd;
	int		read_size;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		ft_msg(file_name, errno);
		return (errno);
	}
	while (1)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size == 0)
			break ;
		if (read_size < 0)
		{
			ft_msg(file_name, errno);
			break ;
		}
		ft_put(buffer, read_size);
	}
	close(fd);
	return (0);
}
