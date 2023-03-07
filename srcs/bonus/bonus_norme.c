/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_norme.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:10:03 by wmessmer          #+#    #+#             */
/*   Updated: 2023/03/07 16:12:11 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

void	ft_gestion_bonus_1(t_pipe_b *pipex)
{
	close(pipex->pipe_fd_b[0]);
	dup2_fd(pipex->infile, STDIN_FILENO);
	dup2_fd(pipex->pipe_fd_b[1], STDOUT_FILENO);
	close(pipex->infile);
	close(pipex->pipe_fd_b[1]);
}

void	ft_gestion_bonus_2(t_pipe_b *pipex)
{
	if (pipex->infile >= 0)
		close(pipex->infile);
	pipex->infile = pipex->pipe_fd_b[0];
	close(pipex->pipe_fd_b[1]);
}
