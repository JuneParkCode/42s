/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:44:45 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/05 13:51:29 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define SUCCESS 0
# define FAILED -1
# define TRUE 1
# define FALSE 0
# define FD_STDIN 1
# define FD_STDERR 2
# define INT_MIN -214743648
# define INT_MAX 214743647

typedef int	t_bool;
typedef int	t_status;

typedef struct	s_map_info
{
	int	**data;
	int	row;
	int	col;
}	t_map_info;

/* MAIN FDF FUNCTION */
t_status	run_fdf(const char *file_name);
/* CHECKK AND GET INPUT FUNCTINOS*/
long long	ft_atoll(const char *str);
t_status	read_and_check_file(const char *file_name, t_map_info **map_info);
int			**convert_string_map_data_to_int_arrs\
				(char **string_map_data, int *row, int *col);
t_bool		is_valid_map_data(char **string_map_data);
/* MLX CONTROL FUNCTINOS  */

/* MAKE MAP INFO */
t_map_info	*create_map_info(int **map_info, const int row, const int col);


#endif
