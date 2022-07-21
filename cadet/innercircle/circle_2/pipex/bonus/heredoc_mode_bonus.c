/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_mode_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 19:52:35 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/21 14:25:23 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include "pipex_bonus.h"
#include "libft.h"

static char	**get_heredoc_mode_argv(int argc, char **argv)
{
	char	**new_argv;
	int		idx;

	new_argv = malloc_errctl(sizeof(char *) * (argc + 1));
	new_argv[0] = ft_strdup(argv[0]);
	new_argv[1] = ft_strdup(TMP_FILE_NAME);
	idx = 3;
	while (idx < argc)
	{
		new_argv[idx - 1] = ft_strdup(argv[idx]);
		++idx;
	}
	new_argv[idx - 1] = NULL;
	return (new_argv);
}

static void	read_and_write_stdin(const int fd, const char *limiter)
{
	const int	limiter_length = ft_strlen(limiter);
	char		*buf;
	int			read_size;
	int			sign_flag;

	buf = malloc_errctl(sizeof(char) * (limiter_length + 1));
	sign_flag = 1;
	while (1)
	{
		if (sign_flag)
			write(STDOUT_FILENO, HEREDOC_SIGN, SIGN_LENGTH);
		read_size = read(STDIN_FILENO, buf, limiter_length);
		buf[read_size] = 0;
		if (ft_strncmp(buf, limiter, -1) == 0)
			break ;
		sign_flag = (ft_strchr(buf, '\n') != NULL);
		write(fd, buf, read_size);
	}
	free(buf);
}

static int	create_doc_file(void)
{
	const int	open_option = O_WRONLY | O_TRUNC | O_CREAT;
	const int	open_mode = S_IREAD | S_IWRITE;
	const int	fd = open(TMP_FILE_NAME, open_option, open_mode);

	if (fd == FAILED)
		put_error_and_exit();
	return (fd);
}

static void	delete_doc_file(void)
{
	if (unlink(TMP_FILE_NAME) == FAILED)
		put_error_and_exit();
}

t_status	do_heredoc_mode(int argc, char **argv, char **envp)
{
	int		tmp_file_fd;
	char	**new_argv;

	tmp_file_fd = create_doc_file();
	read_and_write_stdin(tmp_file_fd, argv[2]);
	close_errctl(tmp_file_fd);
	new_argv = get_heredoc_mode_argv(argc, argv);
	do_commands(argc - 1, new_argv, envp);
	delete_doc_file();
	free_splitted_array(new_argv);
	return (SUCCESS);
}
