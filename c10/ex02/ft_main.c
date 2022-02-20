/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 09:43:45 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/20 18:00:52 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#define BUFFER_SIZE 20000

long long	ft_strcmp(char *s1, char *s2);
void		do_tail_stdin_byte(long long buffer_size, long long length);
void		do_tail_stdin_line(long long buffer_size);
int			do_tail_line(char *file_name, long long len, int flag);
int			do_tail_byte(char *file_name, long long len, int flag);
void		ft_putstr(char *str);
// atoi 구현해!!!!!

int	main(int argc, char *argv[])
{
	long long	idx;
	long long	length;
	int			flag;
	
	flag = 0;
	if (argc == 1)
		do_tail_stdin_line(BUFFER_SIZE);
	else if (argc == 2)
		do_tail_line(argv[1], 10, 0);
	else
	{
		idx = 1;
		if (!ft_strcmp(argv[idx], "-c"))
		{
			length = atoi(argv[++idx]);
			if (argc == 3)
				do_tail_stdin_byte(BUFFER_SIZE, length);
			else
			{
				flag = argc > 4;
				while (++idx < argc)
					flag += do_tail_byte(argv[idx], length, flag);
			}
		}
		else
		{
			length = atoi(argv[idx++]);
			if (!length)
			{
				length = 10;
				idx = 1;
			}
			flag = argc > 3;
			while (idx < argc)
				flag += do_tail_line(argv[idx++], length, flag);
		}
	}
	return (0);
}
