/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:01:59 by wmessmer          #+#    #+#             */
/*   Updated: 2023/02/21 09:51:59 by wmessmer         ###   ########.fr       */
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

void here_doc(char *limiter, t_pipe_b *pipex)
{
    char *line;
    pipex->fd_tmp = open(".tmp", O_CREAT, O_TRUNC, O_RDWR, 777);
    while(1)
    {
        write(1, "heredoc>", 8);
        line = get_next_line(1);
        if (strncmp(line, limiter,ft_strlen(limiter)) == 0)
            break;
        write(pipex->fd_tmp, line, ft_strlen(line));
        wait(NULL);
    }

}