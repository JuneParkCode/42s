/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_parsing_functions.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:40:05 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/21 14:52:27 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "pipex.h"
#include "libft.h"

static char	*get_command_name(char *command_str)
{
	char	**splitted_string;
	char	*command_name;

	splitted_string = ft_split(command_str, ' ');
	command_name = ft_strdup(splitted_string[CMD_PATH_IDX]);
	free_splitted_array(splitted_string);
	return (command_name);
}

static char	**get_env_paths(char **envp)
{
	int	idx;

	idx = 0;
	while (envp[idx])
	{
		if (ft_strncmp(envp[idx], "PATH=", 5) == 0)
			return (ft_split(ft_strchr(envp[idx], '=') + 1, ':'));
		++idx;
	}
	return (NULL);
}

static char	*find_matched_path(char **paths, char *command_name)
{
	char	*command_path;
	char	*path;
	int		idx;

	idx = 0;
	while (paths[idx])
	{
		path = ft_strjoin(paths[idx], "/");
		command_path = ft_strjoin(path, command_name);
		if (access(command_path, X_OK) != FAILED)
		{
			free(command_path);
			return (path);
		}
		free(path);
		free(command_path);
		++idx;
	}
	return (NULL);
}

static char	*get_path_included_command(char *command_str, char **envp)
{
	char	**paths;
	char	*command_name;
	char	*path_command;
	char	*path;

	command_name = get_command_name(command_str);
	path_command = NULL;
	if (access(command_name, X_OK) != FAILED)
		path_command = ft_strdup(command_str);
	else
	{
		paths = get_env_paths(envp);
		path = find_matched_path(paths, command_name);
		free_splitted_array(paths);
		if (path == NULL)
			put_error_and_exit();
		else
			path_command = ft_strjoin(path, command_str);
	}
	free(command_name);
	return (path_command);
}

char	**get_command_argument(char *command, char **envp)
{
	char	**splitted_string;
	char	*path_command;

	path_command = get_path_included_command(command, envp);
	if (ft_strchr(command, '\'') == NULL)
		splitted_string = ft_split(path_command, ' ');
	else
		splitted_string = ft_split_quote_case(path_command, ' ');
	free(path_command);
	return (splitted_string);
}
