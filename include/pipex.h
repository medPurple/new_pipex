/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:24:21 by wmessmer          #+#    #+#             */
/*   Updated: 2023/03/07 11:16:02 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "../libft/include/libft.h"

typedef struct s_pipe
{
	int		infile;
	int		outfile;
	int		begin;
	char	**path;
	char	**argument;
	char	*cmd;
	int		pipe_fd[2];
	pid_t	child;
}	t_pipe;

typedef struct s_pipe_b
{
	int		here;
	int		begin;
	int		infile;
	int		outfile;
	char	*path_env;
	char	**path;
	char	**argument;
	char	*cmd;
	int		pipe_fd_b[2];
	pid_t	child;	
}	t_pipe_b;

/* BONUS */
void	last_pipe(t_pipe_b *pipex, char *cmd, char **env, char *file);
void	multi_pipe(t_pipe_b *pipex, char *cmd, char **env);
int		here_or_not(char *av, t_pipe_b *pipex);
void	here_pipe(char *limiter, t_pipe_b *pipex);
void	ft_gestion_bonus_1(t_pipe_b *pipex);
void	ft_gestion_bonus_2(t_pipe_b *pipex);

/*GENERAL UTILS */
void	pipex_error(int a);
void	close_fd(int *fd);
void	dup2_fd(int fd, int fd2);

/* MANDATORY */
void	get_path_env(t_pipe *pipex, char **env);
void	execute_cmd(t_pipe *pipex, char *bla, char **env);
#endif
