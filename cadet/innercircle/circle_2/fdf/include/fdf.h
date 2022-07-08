/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:44:45 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/08 18:25:20 by sungjpar         ###   ########.fr       */
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

typedef struct	s_mlx_info
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx_info;

/* MAIN FDF FUNCTION */
/* CHECKK AND GET INPUT FUNCTINOS*/
t_bool		is_valid_file_name(const char *file_name);
t_map_info	*get_map_info(const char *file_name);
long long	ft_atoll(const char *str);
t_status	read_and_check_file(const char *file_name, t_map_info **map_info);
int			**convert_string_data_to_int_data\
				(char **string_map_data, int *row, int *col);
t_bool		is_valid_map_data(char **string_map_data);
/* MLX CONTROL FUNCTINOS  */

/* MAKE MAP INFO */
t_map_info	*create_map_info(int **map_info, const int row, const int col);


#endif
