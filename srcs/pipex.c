/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:20:25 by wmessmer          #+#    #+#             */
/*   Updated: 2023/02/17 10:13:52 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
static void pipex_init(t_pipe *pipex,char **env)
{
	pipex->begin = 2;
	pipex->path_env = get_path_env(env);
	if (pipex->path_env)
		pipex->path = ft_split(pipex->path_env, ':');
}
static void execute_cmd(t_pipe *pipex,char *bla, char **env)
{
	pipex->argument = ft_split(bla, ' ');
	if((ft_strchr(pipex->argument[0], '/') != NULL))
		pipex->cmd = pipex->argument[0];
	else
		pipex->cmd = search(pipex->path, pipex->argument[0]);
	if(execve(pipex->cmd, pipex->argument, env) == -1)
	{
		send_error(" Error : Command execution\n");
		exit(1);
	}
}

static void f_pipe(t_pipe *pipex,char *cmd, char **env)
{
	if (pipe(pipex->pipe_fd) < 0)
		pipex_error(2);
	if ((pipex->child = fork()) < 0)
		pipex_error(3);
	if (pipex->child == 0)
	{
		dup2_fd(pipex->pipe_fd[1],STDOUT_FILENO);
		close_fd(pipex->pipe_fd);
		execute_cmd(pipex,cmd,env);
	}
	else
	{
		dup2_fd(pipex->pipe_fd[0],STDIN_FILENO);
		close_fd(pipex->pipe_fd);
	}
}

static void l_pipe(t_pipe *pipex, char *cmd, char **env, char *file)
{
	pipex->outfile = open(file, O_CREAT | O_RDWR |O_TRUNC, 0000644);
	if (pipex->outfile < 0)
		pipex_error(1);
	if ((pipex->child = fork()) < 0)
		pipex_error(3);
	dup2_fd(pipex->outfile,STDOUT_FILENO);
	close(pipex->outfile);
	if (pipex->child == 0)
		execute_cmd(pipex,cmd,env);
}

int	main(int ac, char **av, char **env)
{
	t_pipe	pipex;

	if (ac == 5)
	{
		pipex_init(&pipex, env);
		pipex.infile = open(av[1],O_RDONLY);
		if (pipex.infile < 0)
			pipex_error(0);
		dup2_fd(pipex.infile, STDIN_FILENO);
		close(pipex.infile);
		f_pipe(&pipex,av[pipex.begin],env);
		pipex.begin++;
		l_pipe(&pipex,av[pipex.begin],env,av[ac - 1]);
		while (wait(NULL) > 0);
		ft_free(pipex.path);
		return (0);
	}
	return (send_error("Wrong arg\n"), 0);
}