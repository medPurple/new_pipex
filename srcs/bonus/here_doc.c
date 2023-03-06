/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:01:59 by wmessmer          #+#    #+#             */
/*   Updated: 2023/03/06 19:09:43 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

int here_or_not(char *av,t_pipe_b *pipex)
{
	if(av && (ft_strcmp(av,"here_doc")) == 0)
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

void here_pipe(char *limiter, t_pipe_b *pipex)
{
	char *line;
	if (pipe(pipex->pipe_fd_b) < 0)
        pipex_error(2);
    if ((pipex->child = fork()) < 0)
        pipex_error(3);
    if (pipex->child == 0)
    {
        while(1)
        {
            write(1, "heredoc>", 8);
            line = get_next_line(1);
            if ((strncmp(line, limiter,ft_strlen(limiter)) == 0) && (line[ft_strlen(limiter)] == '\n'))
            {
                close_fd(pipex->pipe_fd_b);
                exit(EXIT_SUCCESS);             
            }
            write(pipex->pipe_fd_b[1], line, ft_strlen(line));
        }
    }
    else
    {
        dup2_fd(pipex->pipe_fd_b[0],STDIN_FILENO);
        close_fd(pipex->pipe_fd_b);
        waitpid(pipex->child, NULL, 0);
    }
}