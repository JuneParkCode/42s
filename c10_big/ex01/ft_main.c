/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 16:30:58 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/21 22:29:16 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <unistd.h>
#include <libgen.h>

void	ft_putstr(char *str);
void	ft_msg(char *str, int err_code);
int		ft_putstdin(void);
int		ft_display_file(char *file_name, char *bs_name);
int		ft_strcmp(char *s1, char *s2);

int	main(int argc, char *argv[])
{
	int		idx;
	int		flag;

	flag = 0;
	if (argc <= 1)
	{
		while (!ft_putstdin())
			;
		return (0);
	}
	idx = 1;
	while (idx < argc)
		ft_display_file(argv[idx++], basename(argv[0]));
	return (0);
}
