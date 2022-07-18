/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 08:51:49 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/18 19:35:47 by sungjpar         ###   ########.fr       */
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
# define BIN_PATH "/bin/"
/* typedefs */
typedef int		t_bool;
typedef int		t_status;
/* pipe functions */
int			build_pipe_and_fork_process(void);
void		set_outlet_pipe(char *outfile_name);
/* check argument functions */
t_bool		is_valid_argument(const int argc, char *argv[]);
/* main functions */
t_status	run_pipex(const int argc, char *argv[]);
t_status	heredoc_mode(const int argc, char *argv[]);
t_status	do_command_from_infile(const int argc, char *argv[]);
t_status	do_command(const int argc, char *argv[], const int no_cmd);
/* parsing functions  */
char		**get_command_option(char *command);
/* create new arguments */
char		**get_new_argv(char **argv);
/* error control functions */
void		put_error_and_exit(void);
void		*error_exit_malloc(const size_t malloc_size);
/* free splitted array */
void		free_splitted_array(char **ptr);

#endif
