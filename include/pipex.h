/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:24:21 by wmessmer          #+#    #+#             */
/*   Updated: 2023/03/05 21:50:09 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/wait.h>
# include "../libft/include/libft.h"

typedef struct s_pipe
{
	char	*file_in;
	char	*file_out;
	int		fd_infile;
	int		fd_outfile;
	int		pipe_fd[2];
	char	*path;
	char	*cmd;
	char	**cmd_path;
	char	**cmd_arg;
	pid_t	child;
	pid_t	parent;
}		t_pipe;

typedef struct s_pipe_b
{
	int here;
    int begin;
	int infile;
	int outfile;
	int cmd_nb;
    char *path_env;
    char **path;
    char **argument;
    char *cmd;
    int fd_tmp;
	int pipe_fd_b[2];
    int fd_test[2];
	pid_t	child;	
}	t_pipe_b;

/* MANDATORY */

void	pipex_init(int ac, char **av, char **env, t_pipe *pipex);
char	*path_env(char **env);
char	*get_cmd(char **paths, char *cmd);
void	child(t_pipe *pipex, char **av, char **env);
void	parent(t_pipe *pipex, char **av, char **env);
void	free_child(t_pipe *pipex);
void	free_parent(t_pipe *pipex);
void	close_pipe(t_pipe *pipex);

/* BONUS */
void first_pipe(t_pipe_b *pipex, char *cmd, char **env);
void last_pipe(t_pipe_b *pipex,char *cmd, char **env);
void multi_pipe(t_pipe_b *pipex,char *cmd, char **env);
void	bonus_init(char **av, int ac,t_pipe_b *pipex, char **env);
void bonus_error(int a);
int here_or_not(char *av,t_pipe_b *pipex);
void here_pipe(char *limiter, t_pipe_b *pipex);
void execute_cmd(t_pipe_b *pipex,char *cmd, char **env);
#endif
