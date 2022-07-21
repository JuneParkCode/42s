/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 08:51:49 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/21 14:33:15 by sungjpar         ###   ########.fr       */
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
/* check argument functions */
t_bool		check_valid_argument(const int argc);
/* run command function */
t_status	do_commands(int argc, char **argv, char **envp);
/* argument parsing functions  */
char		**get_command_argument(char *command, char **envp);
char		**get_inlet_argv(char **argv, char **envp);
char		**ft_split_quote_case(char const *s, char c);
/* error control functions */
void		put_error_and_exit(void);
void		*malloc_errctl(const size_t malloc_size);
int			fork_errctl(void);
void		close_errctl(int fd);
void		pipe_errctl(int pipeline[2]);
/* free splitted array */
void		free_splitted_array(char **ptr);
/* execute function */
t_status	execute_command(const char *command_path, char **argv);
/* fd control function */
void		set_outlet_fd(char *outfile_name);
void		set_process_to_process_fd(\
	const int no_cmd, const int number_of_commands, \
	int pipelines[2][2], char **argv);
#endif
