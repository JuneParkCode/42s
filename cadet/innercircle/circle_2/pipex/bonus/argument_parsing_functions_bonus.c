/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_parsing_functions_bonus.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:40:05 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/20 19:55:26 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "pipex_bonus.h"
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

static char	*get_path_included_command(char *command_str)
{
	char	*command_name;
	char	*path_command;

	command_name = get_command_name(command_str);
	if (access(command_name, X_OK) != FAILED)
		path_command = ft_strdup(command_str);
	else
	{
		command_name = ft_strjoin(BIN_PATH, command_name);
		if (access(command_name, X_OK) == FAILED)
			path_command = ft_strjoin(USR_BIN_PATH, command_str);
		else
			path_command = ft_strjoin(BIN_PATH, command_str);
	}
	free(command_name);
	return (path_command);
}

char	**get_command_argument(char *command)
{
	char	**splitted_string;
	char	*path_command;

	path_command = get_path_included_command(command);
	if (ft_strchr(command, '\'') == NULL)
		splitted_string = ft_split(path_command, ' ');
	else
		splitted_string = ft_split_quote_case(path_command, ' ');
	free(path_command);
	return (splitted_string);
}
