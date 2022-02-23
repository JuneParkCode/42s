/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:20:14 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/23 19:49:24 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BSQ_H
# define FT_BSQ_H
# include <stdlib.h>
typedef struct s_pair
{
	int	row;
	int	col;
}		t_pair;
typedef	struct s_rules
{
	int		map_row;
	int		map_col;
	char	empty;
	char	obstacle;
	char	full;
	t_pair	*result;
}		t_rules;
char	**read_file(char *file_name);
int		is_valid_input(char **strs);
t_rules	*get_rule(char *rule_str);
int		ft_atoi(char *str, int len);
int		ft_strlen(char *str);
int		ft_is_printable(char c);
void	ft_puterr(char *str);
int 	ft_atoi(char *str, int len);
#endif
