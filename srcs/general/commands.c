/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:47:31 by wmessmer          #+#    #+#             */
/*   Updated: 2023/03/07 15:47:35 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

void	close_fd(int *fd)
{
	if (close(fd[0]) < 0)
		pipex_error(4);
	if (close(fd[1]) < 0)
		pipex_error(4);
}

void	dup2_fd(int fd, int fd2)
{
	if (dup2(fd, fd2) < 0)
		pipex_error(5);
}

void	pipex_error(int a)
{
	if (a == 0)
		send_error("Can't open infile\n");
	if (a == 1)
		send_error("Can't open outfile\n");
	if (a == 2)
		send_error("Pipe error\n");
	if (a == 3)
		send_error("Fork error\n");
	if (a == 4)
		send_error("Close error\n");
	if (a == 5)
		send_error("Dup2 error\n");
	if (a == 6)
		send_error("Execution\n ");
	perror(" Error ");
	exit(1);
}
