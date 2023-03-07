/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:20:25 by wmessmer          #+#    #+#             */
/*   Updated: 2023/03/07 15:32:19 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	ft_gestion(t_pipe *pipex)
{
	close(pipex->pipe_fd[0]);
	dup2_fd(pipex->infile, STDIN_FILENO);
	dup2_fd(pipex->pipe_fd[1], STDOUT_FILENO);
	close(pipex->infile);
	close(pipex->pipe_fd[1]);
}

static void	pipex_init(t_pipe *pipex, char **env)
{
	pipex->begin = 2;
	pipex->path = NULL;
	get_path_env(pipex, env);
}

static void	f_pipe(t_pipe *pipex, char *cmd, char **env)
{
	if (pipe(pipex->pipe_fd) < 0)
		pipex_error(2);
	pipex->child = fork();
	if (pipex->child < 0)
		pipex_error(3);
	if (pipex->child == 0)
	{
		if (pipex->infile < 0)
		{
			if (pipex->path)
				ft_free(pipex->path);
			close_fd(pipex->pipe_fd);
			exit(EXIT_FAILURE);
		}
		ft_gestion(pipex);
		execute_cmd(pipex, cmd, env);
	}
	else
	{
		if (pipex->infile >= 0)
			close(pipex->infile);
		pipex->infile = pipex->pipe_fd[0];
		close(pipex->pipe_fd[1]);
	}
}

static void	l_pipe(t_pipe *pipex, char *cmd, char **env, char *file)
{
	pipex->outfile = open(file, O_CREAT | O_RDWR | O_TRUNC, 0000644);
	if (pipex->outfile < 0)
	{
		if (pipex->path)
			ft_free(pipex->path);
		close(pipex->infile);
		pipex_error(1);
	}
	pipex->child = fork();
	if (pipex->child < 0)
		pipex_error(3);
	if (pipex->child == 0)
	{
		dup2_fd(pipex->infile, STDIN_FILENO);
		dup2_fd(pipex->outfile, STDOUT_FILENO);
		close(pipex->outfile);
		close(pipex->infile);
		execute_cmd(pipex, cmd, env);
	}
	else
	{
		close(pipex->outfile);
		close(pipex->infile);
	}
}

int	main(int ac, char **av, char **env)
{
	t_pipe	pipex;

	if (ac == 5)
	{
		pipex_init(&pipex, env);
		pipex.infile = open(av[1], O_RDONLY);
		if (pipex.infile < 0)
		{
			if (pipex.path)
				ft_free(pipex.path);
			pipex_error(0);
		}
		f_pipe(&pipex, av[pipex.begin], env);
		pipex.begin++;
		l_pipe(&pipex, av[pipex.begin], env, av[ac - 1]);
		while (wait(NULL) > 0)
			;
		if (pipex.path)
			ft_free(pipex.path);
		return (0);
	}
	return (send_error("Wrong arg\n"), 0);
}
