/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:43:41 by sungjpar          #+#    #+#             */
/*   Updated: 2022/03/24 10:17:17 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "include/libft_printf.h"
#include "../libft/libft.h"

char	*makered(const char *s)
{
	char	*temp;
	temp = ft_strjoin("\033[0;31m", s);
	return (ft_strjoin(temp, "\033[0m"));
}

char	*makegreen(const char *s)
{
	char	*temp;
	temp = ft_strjoin("\033[0;32m", s);
	return (ft_strjoin(temp, "\033[0m"));
}

char	*makeblue(const char *s)
{
	char	*temp;
	temp = ft_strjoin("\033[0;34m", s);
	return (ft_strjoin(temp, "\033[0m"));
}

void	do_test(const char type, void *arg)
{
	int x, y;
	switch (type)
	{
		case 's':
			x = printf("pr\t: %s\n", (char *)arg);
			y = ft_printf("ft\t: %s\n", (char *)arg);
			break;
		case 'p':
			x = printf("pr\t: %p\n", arg);
			y = ft_printf("ft\t: %p\n", arg);
			break;
		case 'c':
			x = printf("pf\t: %c\n", *((char *)arg));
			y = ft_printf("ft\t: %c\n",  *((char *)arg));
			break;
		case 'd':
			x = printf("pf\t: %d\n", *((int *)arg));
			y = ft_printf("ft\t: %d\n", *((int *)arg));
			break;
		case 'i':
			x = printf("pf\t: %i\n", *((int *)arg));
			y = ft_printf("ft\t: %i\n", *((int *)arg));
			break;
		case 'u':
			x = printf("pf\t: %u\n", *((int *)arg));
			y = ft_printf("ft\t: %u\n", *((int *)arg));
			break;
		case 'x':
			x = printf("pf\t: %x\n", *((int *)arg));
			y = ft_printf("ft\t: %x\n", *((int *)arg));
			break;
		case 'X':
			x = printf("pf\t: %X\n", *((int *)arg));
			y = ft_printf("ft\t: %X\n", *((int *)arg));
			break;
		case '%':
			x = printf("pf\t: %%\n");
			y = ft_printf("ft\t: %%\n");
			break;
	}
	if (x == y)
		ft_putstr(makegreen("SUCCESS\n"));
	else
	{
		ft_putstr(makered("FAILED\n"));
		ft_putstr("o : "); ft_putnbr(x); ft_putchar('\n');
		ft_putstr("f : "); ft_putnbr(y); ft_putchar('\n');
		
	}
	printf("==========\n");
}

#include <limits.h>

int	main(void)
{
	char	*test;

	test = malloc(1);
	int	x;

	// do_test p
	ft_printf(makeblue("========[TEST : p]==========\n"));
	do_test('p', test);
	do_test('p', NULL);

	// do_test c
	ft_printf(makeblue("========[TEST : c]==========\n"));
	char	c;
	c = 0;
	do_test('c', &c);
	c = INT_MIN;
	do_test('c', &c);
	c = INT_MAX;
	do_test('c', &c);
	c = 'A';
	do_test('c', &c);
	c = 'z';
	do_test('c', &c);

	// do test u
	ft_printf(makeblue("========[TEST : u]==========\n"));
	x = INT_MIN;
	do_test('u', &x);
	x = INT_MAX;
	do_test('u', &x);
	x = 0;
	do_test('u', &x);
	x = -1;
	do_test('u', &x);
	x = 123;
	do_test('u', &x);


	ft_printf(makeblue("========[TEST : d]==========\n"));
	x = INT_MIN;
	do_test('d', &x);
	x = INT_MAX;
	do_test('d', &x);
	x = 0;
	do_test('d', &x);
	x = 123;
	do_test('d', &x);
	x = -123;
	do_test('d', &x);

	
	ft_printf(makeblue("========[TEST : i]==========\n"));
	x = INT_MIN;
	do_test('i', &x);
	x = INT_MAX;
	do_test('i', &x);
	x = 0;
	do_test('i', &x);
	x = 123;
	do_test('i', &x);
	x = -123;
	do_test('i', &x);

	ft_printf(makeblue("========[TEST : s]==========\n"));
	do_test('s', "HELLO WORLD");
	do_test('s', NULL);
	do_test('s', "");
	
	ft_printf(makeblue("========[TEST : x]==========\n"));
	x = 0x123;
	do_test('x', &x); 
	x = -1;
	do_test('x', &x); 
	x = INT_MIN;
	do_test('x', &x); 
	x = INT_MAX;
	do_test('x', &x); 
	x = 0;
	do_test('x', &x); 
	
	ft_printf(makeblue("========[TEST : X]==========\n"));
	x = 0x123;
	do_test('X', &x); 
	x = -1;
	do_test('X', &x); 
	x = INT_MIN;
	do_test('X', &x); 
	x = INT_MAX;
	do_test('X', &x); 
	x = 0;
	do_test('X', &x); 

	ft_printf(makeblue("========[TEST : %]==========\n"));
	do_test('%', NULL); 
	x = 0;
}
