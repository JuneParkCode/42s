/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:16:34 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/14 10:18:55 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putstr(const char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int				i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	while (str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		++i;
	}
	return (str1[i] - str2[i]);
}

void	ft_swap(char **s1, char **s2)
{
	char	*temp;

	temp = *s2;
	*s2 = *s1;
	*s1 = temp;
}

int	ft_sort(int size, char *args[])
{
	int	i;
	int	j;

	i = 1;
	if (size < 1)
		return (0);
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (ft_strcmp(args[i], args[j]) > 0)
				ft_swap(&args[i], &args[j]);
			++j;
		}
		++i;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	int	i;

	i = 1;
	if (!ft_sort(argc, argv))
		return (0);
	while (i < argc)
	{
		ft_putstr(argv[i]);
		ft_putstr("\n");
		++i;
	}
	return (0);
}
