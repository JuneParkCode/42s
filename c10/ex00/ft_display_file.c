/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 19:03:11 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/17 19:32:03 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}
/*
 *  ft_check_input_error
 *  Description		:	function checks input error
 *	return value	:	1	: Missing file name
 *						2	: Too many arguments
 *						0	: Success
 */
int	ft_check_input_error(int argc, char *argv[])
{
	if (argc < 1)
	{
		ft_putstr("File name missing.\n");
		return (1);
	}
	if (argc > 1)
	{
		ft_putstr("Too many arguments.\n");
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
int	ft_display_file(int argc, char *argv[])
{
	char	*path_name;
	char	content[1000];
	int		fd;
	
	if (!ft_check_input_error(argc, argv))
		return (1);
	path_name = argv[1];
	fd = open(path_name, O_RDONLY);
	if (fd == -1)
	{
		perror("Cannot read file.");
		return (2);
	}

	return (0);
}

