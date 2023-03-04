/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:06:46 by wmessmer          #+#    #+#             */
/*   Updated: 2023/02/17 10:43:37 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

void	pipex_init(int ac, char **av, char **env, t_pipe *pipex)
{
	pipex->file_in = av[1];
	pipex->file_out = av[ac - 1];
	pipex->fd_infile = open(pipex->file_in, O_RDONLY);
	if (pipex->fd_infile < 0)
	{
		send_error("Can't open infile\n");
		exit (1);
	}
	pipex->fd_outfile = open(pipex->file_out, O_TRUNC \
		| O_CREAT | O_RDWR, 0000644);
	if (pipex->fd_outfile < 0)
	{
		send_error("Can't open outfile\n");
		exit (1);
	}
	pipex->path = path_env(env);
	if (pipex->path)
		pipex->cmd_path = ft_split(pipex->path, ':');
}

char	*path_env(char **env)
{
	if (!*env)
		return(NULL);
	while (ft_strncmp("PATH", *env, 4))
		env++;
	return (*env + 5);
}

char	*get_cmd(char **paths, char *cmd)
{
	char	*tmp;
	char	*command;
	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		command = ft_strjoin(tmp, cmd);
		if (access(command, 0) == 0)
			return (command);
		free(command);
		paths++;
	}
	send_error("command don't exist\n");
	return (NULL);
}

void	close_pipe(t_pipe *pipex)
{
	close(pipex->pipe_fd[0]);
	close(pipex->pipe_fd[1]);
}
