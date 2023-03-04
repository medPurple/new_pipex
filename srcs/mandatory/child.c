/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                     		:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:51:52 by wmessmer          #+#    #+#             */
/*   Updated: 2023/02/03 16:11:50 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

void	child(t_pipe *pipex, char **av, char **env)
{
	dup2(pipex->pipe_fd[1], 1);
	close(pipex->pipe_fd[0]);
	dup2(pipex->fd_infile, 0);
	pipex->cmd_arg = ft_split(av[2], ' ');
	if (!(ft_strchr(av[1],'/')))
		pipex->cmd =  pipex->cmd_arg[0];
	else
		pipex->cmd = get_cmd(pipex->cmd_path, pipex->cmd_arg[0]);
	if(execve(pipex->cmd, pipex->cmd_arg, env) == -1)
	{
		free_child(pipex);
		free_parent(pipex);
		send_error("can't execute cmd one\n");
		exit(1);
	}
}

void	parent(t_pipe *pipex, char **av, char **env)
{
	dup2(pipex->pipe_fd[0], STDIN_FILENO);
	close(pipex->pipe_fd[1]);
	dup2(pipex->fd_outfile, STDOUT_FILENO);
	pipex->cmd_arg = ft_split(av[3], ' ');
	if (!(ft_strchr(av[3],'/')))
		pipex->cmd =  pipex->cmd_arg[0];
	else
		pipex->cmd = get_cmd(pipex->cmd_path, pipex->cmd_arg[0]);
	if(execve(pipex->cmd, pipex->cmd_arg, env) == -1)
	{
		free_child(pipex);
		free_parent(pipex);
		send_error("can't execute cmd two\n");
		exit(1);
	}
}