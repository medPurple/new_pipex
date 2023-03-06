//
// Created by wmessmer on 3/4/23.
//
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

void pipex_error(int a)
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
	perror(" Error ");
	exit(1);
}