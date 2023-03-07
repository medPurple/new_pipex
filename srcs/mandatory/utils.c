/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:42:48 by wmessmer          #+#    #+#             */
/*   Updated: 2023/03/07 15:42:51 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

void	get_path_env(t_pipe *pipex, char **env)
{
	if (!*env)
		return ;
	while (*env)
	{
		if (ft_strncmp("PATH", *env, 4) == 0)
		{
			pipex->path = ft_split(*env + 5, ':');
			return ;
		}
		env++;
	}
	return ;
}

static char	*search(t_pipe *pipex)
{
	char	*tmp;
	char	*command;
	int		i;

	i = 0;
	if (!(pipex->path))
	{
		ft_free(pipex->argument);
		send_error("ERROR\n No path to search\n");
		exit(EXIT_FAILURE);
	}
	while (pipex->path[i])
	{
		tmp = ft_strjoin(pipex->path[i], "/");
		command = ft_strjoin(tmp, pipex->argument[0]);
		if (access(command, 0) == 0)
			return (command);
		free(command);
		i++;
	}
	free(pipex->path);
	ft_free(pipex->argument);
	send_error("ERROR :\n can't find the cmd\n");
	exit(EXIT_FAILURE);
}

void	execute_cmd(t_pipe *pipex, char *bla, char **env)
{
	pipex->argument = ft_split(bla, ' ');
	if ((ft_strchr(pipex->argument[0], '/') != NULL))
		pipex->cmd = pipex->argument[0];
	else
		pipex->cmd = search(pipex);
	if (pipex->cmd)
	{
		if (execve(pipex->cmd, pipex->argument, env) == -1)
		{
			if (pipex->path)
				ft_free(pipex->path);
			ft_free(pipex->argument);
			pipex_error(6);
			exit(1);
		}
	}
}
