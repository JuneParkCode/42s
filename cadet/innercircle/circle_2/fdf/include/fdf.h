/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:44:45 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/10 19:20:38 by sungjpar         ###   ########.fr       */
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
# define ROTATION_UNIT 100
# define MOVE_MARGIN_UNIT 100
# define WINDOW_SIZE_WIDTH 1920
# define WINDOW_SIZE_HEIGHT 1080
/* DEFINE KEYS */
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_Z 6
# define KEY_X 7
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_ESC 53
# define KEY_PLUS 24
# define KEY_MINUS 27
# define KEY_I 34
# define KEY_P 35

typedef int	t_bool;
typedef int	t_status;

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}	t_vector;

typedef struct s_map_info
{
	int	**data;
	int	row;
	int	col;
}	t_map_info;

typedef struct s_pixel
{
	int	x;
	int	y;
	int	color;
}	t_pixel;

typedef t_pixel**\
			t_screen_data;

typedef struct s_mlx_info
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx_info;

typedef struct s_camera
{
	double	x_axis_angle;
	double	y_axis_angle;
	double	z_axis_angle;
	int		zoom;
	int		margin_x;
	int		margin_y;
}	t_camera;

typedef struct s_vars
{
	t_mlx_info		*mlx_info;
	t_map_info		*original_map;
	t_screen_data	screen_data;
	t_camera		*camera;
}	t_vars;

/* CHECKK AND GET INPUT FUNCTINOS*/
t_bool			is_valid_file_name(const char *file_name);
t_map_info		*get_map_info(const char *file_name);
long long		ft_atoll(const char *str);
t_status		read_and_check_file(\
					const char *file_name, \
					t_map_info **map_info);
int				**convert_string_data_to_int_data(\
					char **string_map_data, \
					int *row, \
					int *col);
t_bool			is_valid_map_data(char **string_map_data);

/* CAMERA CONTROL FUNCTIONS */
void			init_cam(t_camera *camera);
void			set_isometric_cam(t_camera *camera);
void			set_parallel_cam(t_camera *camera);

/* DRAW FUNCTINOS  */
void			draw_line(\
					const t_pixel pixel1, \
					const t_pixel pixel2, \
					const t_vars *vars);
void			draw_pixel(const t_pixel *pixel, const t_vars *vars);
void			draw_screen(t_vars *vars);

/* ROTATION FUNCTIONS */
t_vector		rotate_vector(const t_vector vector, const t_camera *cam);
t_vector		rotate_x_axis(const t_vector v, const double theta);
t_vector		rotate_y_axis(const t_vector v, const double theta);
t_vector		rotate_z_axis(const t_vector v, const double theta);

/* SCREEN DATA CONTROL FUNCTIONS */
t_screen_data	get_new_screen_data(t_map_info *original_map);
void			update_screen_data_in_new_cam(t_vars *vars);

/* PROJECTION */
t_pixel			vector_projection_to_pixel(\
					const t_vector vector, \
					const int color);

/* CREATE MAP INFO */
t_map_info		*create_map_info(int **map_info, const int row, const int col);

/* COLOR CONTROL */
int				get_color(const int z);

/* KEY HOOKS */
int				key_hook_rotation(int key_code, t_vars *vars);
int				key_hook_exit(int key_code, t_vars *vars);
int				key_hook_move(int key_code, t_vars *vars);
int				key_hook_zoom(int key_code, t_vars *vars);
int				key_hook_funcs(int key_code, t_vars *vars);

/* EXIT FREE */
void			free_and_exit(t_vars *vars);
void			free_splited_string(char **splited_strings);
#endif
