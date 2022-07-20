/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 08:51:49 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/20 17:58:18 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H

# include <stddef.h>
/* t_bool t/f define */
# define TRUE 1
# define FALSE 0
/* t_status status define */
# define SUCCESS 0
# define FAILED -1
/* pipe index define */
# define PIPE_INDEX_READ 0
# define PIPE_INDEX_WRITE 1
/* pid define */
# define CHILD_PROCESS_PID 0
/* PATH define */
# define USR_BIN_PATH "/usr/bin/"
# define BIN_PATH "/bin/"
/* MAIN ARGUMENT INDEX define */
# define INFILE_IDX 1
# define FIRST_CMD_IDX 2
/* command argument index define */
# define CMD_PATH_IDX 0

/* typedefs */
typedef int		t_bool;
typedef int		t_status;
/* pipe functions */
int			build_pipe_and_fork_process(void);
int			build_pipe_and_fork_process_parallel(int argc, char *argv[]);
void		set_outlet_pipe(char *outfile_name);
/* check argument functions */
t_bool		is_valid_argument(const int argc);
/* main functions */
t_status	run_pipex(const int argc, char *argv[]);
t_status	do_command_from_infile(const int argc, char *argv[]);
t_status	do_command(const int argc, char *argv[], const int no_cmd);
t_status	do_commands(int argc, char **argv);
/* parsing functions  */
char		**get_command_argument(char *command);
char		**get_inlet_argv(char **argv);
char		**ft_split_quote_case(char const *s, char c);
/* create new arguments */
char		**get_new_argv(char **argv);
/* error control functions */
void		put_error_and_exit(void);
void		*error_controlled_malloc(const size_t malloc_size);
int			error_controlled_fork(void);
void		error_controlled_close(int fd);
void		error_controlled_pipe(int pipeline[2]);
/* free splitted array */
void		free_splitted_array(char **ptr);
/* execute function */
t_status	execute_command(const char *command_path, char **argv);
/* fd control function */
void		set_inlet_fd(char *infile_name);
void		set_outlet_fd(char *outfile_name);
void		set_process_to_process_fd(\
	const int no_cmd, const int number_of_commands, int pipelines[2][2]);

#endif
