/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:01:59 by wmessmer          #+#    #+#             */
/*   Updated: 2023/03/07 13:34:39 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

static void	ft_gestion_before(t_pipe_b *pipex)
{
	if (pipe(pipex->pipe_fd_b) < 0)
		pipex_error(2);
	pipex->child = fork();
	if (pipex->child < 0)
		pipex_error(3);
}

static void	ft_gestion_parent(t_pipe_b *pipex)
{
	dup2_fd(pipex->pipe_fd_b[0], STDIN_FILENO);
	pipex->infile = pipex->pipe_fd_b[0];
	close(pipex->pipe_fd_b[1]);
	waitpid(pipex->child, NULL, 0);
}

int	here_or_not(char *av, t_pipe_b *pipex)
{
	if (av && (ft_strcmp(av, "here_doc")) == 0)
	{
		pipex->here = 1;
		return (6);
	}
	else
	{
		pipex->here = 0;
		return (5);
	}
}

void	here_pipe(char *limiter, t_pipe_b *pipex)
{
	char	*line;

	ft_gestion_before(pipex);
	if (pipex->child == 0)
	{
		while (1)
		{
			write(1, "heredoc>", 8);
			line = get_next_line(1);
			if ((strncmp(line, limiter, ft_strlen(limiter)) == 0) \
				&& (line[ft_strlen(limiter)] == '\n'))
			{
				free(line);
				if (pipex->path)
					ft_free(pipex->path);
				close_fd(pipex->pipe_fd_b);
				exit(EXIT_SUCCESS);
			}
			write(pipex->pipe_fd_b[1], line, ft_strlen(line));
			free(line);
		}
	}
	else
		ft_gestion_parent(pipex);
}
