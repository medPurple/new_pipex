//
// Created by wmessmer on 3/4/23.
//
#include "../../include/pipex.h"

void	close_fd(int *fd)
{
	if (close(fd[0]) < 0)
		bonus_error(4);
	if (close(fd[1]) < 0)
		bonus_error(4);
}

void	dup2_fd(int fd, int fd2)
{
	if (dup2(fd, fd2) < 0)
		bonus_error(5);
}