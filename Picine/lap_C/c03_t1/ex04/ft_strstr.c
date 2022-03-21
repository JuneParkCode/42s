/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:44:54 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/08 14:45:23 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	str_length;
	int	fstr_length;

	str_length = ft_strlen(str);
	fstr_length = ft_strlen(to_find);
	if (!fstr_length)
		return (str);
	i = 0;
	j = 0;
	while (str[i] && to_find[j])
	{
		if (str[i] == to_find[j])
			++j;
		else
			j = 0;
		if (j == fstr_length)
			return (&str[i - j + 1]);
		++i;
	}
	return (0);
}
