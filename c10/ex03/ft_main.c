/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 14:25:21 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/20 21:37:59 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUFFER_SIZE 16

void	hexdump(char *file_name, char *buf_current, char *buf_prev);
void	hexdump_c(char *file_name, char *buf_current, char *buf_prev);
void	hexdump_stdin(char *buf_current, char *buf_prev);

int	main(int argc, char *argv[])
{
	char	buf_current[16];
	char	buf_prev[16];
	int		idx;

	hexdump(argv[1], buf_current, buf_prev);
/*	
	if (argc == 1)
	{
		hexdump_stdin(buf_current, buf_prev);
		return (0);
	}
	if (strcmp(argv[1], "-C") == 0)
	{
		idx = 2;
		if (argc == 2)
		{
			hexdump_c_stdin(buf_current, buf_prev);
			return (0);
		}
		while (idx < argc)
			hexdump_c(argv[idx++], buf_current, buf_prev);
	}
	else
	{
		idx = 1;
		while (idx < argc)
			hexdump(argv[idx++], buf_current, buf_prev);
	}
*/
	return (0);
}
