/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:44:45 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/09 20:33:58 by sungjpar         ###   ########.fr       */
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
# define ROTATION_UNIT 1000
# define MOVE_MARGIN_UNIT 100

typedef int	t_bool;
typedef int	t_status;

typedef struct	s_vector
{
	double	x;
	double	y;
	double	z;
}	t_vector;

typedef struct	s_map_info
{
	int	**data;
	int	row;
	int	col;
}	t_map_info;

typedef struct	s_pixel
{
	int	x;
	int	y;
	int	color;
}	t_pixel;

typedef t_pixel** t_screen_data;

typedef struct	s_mlx_info
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx_info;

typedef struct	s_camera
{
	double	x_axis_angle;
	double	y_axis_angle;
	double	z_axis_angle;
	int		zoom;
	int		margin_x;
	int		margin_y;
}	t_camera;

typedef struct	s_vars
{
	t_mlx_info		*mlx_info;
	t_map_info		*original_map;
	t_screen_data	screen_data;
	t_camera		*camera;
}	t_vars;

/* MAIN FDF FUNCTION */
/* CHECKK AND GET INPUT FUNCTINOS*/
t_bool			is_valid_file_name(const char *file_name);
t_map_info		*get_map_info(const char *file_name);
long long		ft_atoll(const char *str);
t_status		read_and_check_file\
				(\
				 const char *file_name,\
				 t_map_info **map_info\
				 );
int				**convert_string_data_to_int_data\
				(\
				 char **string_map_data,\
				 int *row,\
				 int *col\
				 );
t_bool			is_valid_map_data(char **string_map_data);
/* MLX CONTROL FUNCTINOS  */
void			draw_line(const t_pixel pixel1, const t_pixel pixel2, const t_vars *vars);

/* ROTATION FUNCTIONS */
t_vector		rotate_vector(const t_vector vector, const t_camera *cam);
t_vector		rotate_x_axis(const t_vector v, const double theta);
t_vector		rotate_y_axis(const t_vector v, const double theta);
t_vector		rotate_z_axis(const t_vector v, const double theta);

/* SCREEN DATA CONTROL FUNCTIONS */
t_screen_data	get_new_screen_data(t_map_info *original_map);
void			update_screen_data_in_new_cam\
				(\
				 t_screen_data screen_datas,\
				 t_map_info *original_map,\
				 t_camera *cam\
				 );

/* PROJECTION */
t_pixel			vector_projection_to_pixel\
				(\
				 const t_vector vector,\
				 const int color\
				 );

/* MAKE MAP INFO */
t_map_info		*create_map_info(int **map_info, const int row, const int col);


#endif
