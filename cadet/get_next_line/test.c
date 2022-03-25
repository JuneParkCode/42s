/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:43:41 by sungjpar          #+#    #+#             */
/*   Updated: 2022/03/25 18:13:43 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "include/get_next_line.h"
#include "libft.h"
#include <limits.h>

char	*makered(const char *s)
{
	char	*temp;
	temp = ft_strjoin("\033[1;31m", s);
	return (ft_strjoin(temp, "\033[0m"));
}

char	*makegreen(const char *s)
{
	char	*temp;
	temp = ft_strjoin("\033[1;32m", s);
	return (ft_strjoin(temp, "\033[0m"));
}

char	*makeblue(const char *s)
{
	char	*temp;
	temp = ft_strjoin("\033[1;34m", s);
	return (ft_strjoin(temp, "\033[0m"));
}

char	*makeyellow(const char *s)
{
	char	*temp;
	temp = ft_strjoin("\033[1;33m", s);
	return (ft_strjoin(temp, "\033[0m"));
}

void	do_test(const int x, const int y)
{
	int	x, y;

	if (x == y)
		printf(makegreen("SUCCESS\n"));
	else
	{
		printf(makered("FAILED\n"));
		printf("assert : %d\n", x);
		printf("result : %d\n", y);
	}
	printf("==========\n");
}

void	do_test_str(const char *x, const char *y)
{
	int	x, y;

	if (ft_strcmp(x, y) == 0)
		printf(makegreen("SUCCESS\n"));
	else
	{
		printf(makered("FAILED\n"));
		printf("assert : %s\n", x);
		printf("result : %s\n", y);
	}
}

int	main(void)
{
	char	*test;

	printf(makeblue("========[TEST : has_lr]==========\n"));
	test = "1234";
	do_test(-1, has_lr(test));
	do_test(-1, has_lr(0)); // NULL 체크의 경우 안되는게 당연할듯.
	test = "12345\nfsafsd";
	do_test(5, has_lr(test));
	test = "1234\n";
	do_test(4, has_lr(test));
	
	printf(makeblue("========[TEST : get_residue]==========\n"));
	test = "12345\nfsafsd";
	do_test_str("fsafsd", get_residue(test, 5));
}
