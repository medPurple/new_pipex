/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pipe.c                         	            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:59:43 by wmessmer          #+#    #+#             */
/*   Updated: 2023/02/03 16:17:07 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

void	free_child(t_pipe *pipex)
{
	int	i;

	i = 0;
	while (pipex->cmd_arg[i])
	{
		free(pipex->cmd_arg[i]);
		i++;
	}
	free(pipex->cmd_arg);
}

void	free_parent(t_pipe *pipex)
{
	int	i;

	i = 0;
	close(pipex->fd_infile);
	close(pipex->fd_outfile);
	if (pipex->path)
	{	
		while (pipex->cmd_path[i])
		{
			free(pipex->cmd_path[i]);
			i++;
		}
		free(pipex->cmd_path);
	}
}