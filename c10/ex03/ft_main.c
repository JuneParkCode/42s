/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 14:25:21 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/20 22:17:44 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUFFER_SIZE 16

long	hexdump(char *file_name, char *buf_current, char *buf_prev, long addr);
void	hexdump_c(char *file_name, char *buf_current, char *buf_prev, long addr);
void	hexdump_stdin(char *buf_current, char *buf_prev);

int	main(int argc, char *argv[])
{
	char	buf_current[16];
	char	buf_prev[16];
	int		idx;
	long	addr;

	idx = 1;
	addr = 0;
	while (idx < argc)
		addr = hexdump(argv[idx++], buf_current, buf_prev, addr);
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
