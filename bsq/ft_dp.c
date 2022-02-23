/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingylee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:56:44 by mingylee          #+#    #+#             */
/*   Updated: 2022/02/23 20:36:18 by mingylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	find_min(int left_up, int up, int left)
{
	int	min;

	if (left_up == 0 || up == 0 || left == 0)
		return (0);
	min = left_up;
	if (left_up > up)
		min = up;
	if (up > left)
		min = left;
	return (min);
}

int	find_max(int **map, int i, int j, t_rules *rules)
{
	t_rules -> result -> col = j;
	t_rules -> result -> row = i;
	return (tab[i][j]);
}

void	dp(int **map, t_rules *rules)
{
	int	i;
	int	j;
	int	min;
	int	max;

	i = 0;
	j = 0;
	while (i < rules.map_col)
	{
		while (j < rules.map_row)
		{
			if (tab[i][j] != 0)
			{
				min = find_min(tab[i - 1][j - 1],\
					tab[i - 1][j], tab[i][j - 1]);
				if (min != 0)
					tab[i][j] = min + 1;
				if (max < tab[i][j])
					max = find_max(tab, i, j, rules);
			}
			j++;
		}
		i++;
	}
}
