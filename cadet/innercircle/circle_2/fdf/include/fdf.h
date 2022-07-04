/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:44:45 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/04 19:26:35 by sungjpar         ###   ########.fr       */
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

typedef int	t_bool;
typedef int	t_status;

typedef struct	s_map_info
{
	int	**data;
	int	row;
	int	col;
}	t_map_info;

/* MAIN FDF FUNCTION */
t_status	run_fdf(int argc, char *argv[]);
/* CHECKK AND GET INPUT FUNCTINOS*/
t_status	read_and_check_file(const char *file_name, t_map_info **map_info);
// | read file
t_bool		is_all_digits(char **raw_string_map_data);
// | check map is retangle
t_bool		is_retangle(char ***converted_string_map_data);
// | if ALL OK, convert string into int
int			**convert_into_int(char **raw_string_map_data);
/* MLX CONTROL FUNCTINOS  */

/* MAKE MAP INFO */
t_map_info	*get_map_data(const int **map_info, const int row, const int col);

#endif
