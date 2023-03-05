/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:18:23 by wmessmer          #+#    #+#             */
/*   Updated: 2023/03/05 18:37:30 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"
static char *get_path_env(char **env)
{
    if (!*env)
        return(NULL);
    while (ft_strncmp("PATH", *env, 4))
        env++;
    return (*env + 5);
}

void	bonus_init(char **av, int ac,t_pipe_b *pipex, char **env)
{
	if (pipex->here == 0)
	{
		pipex->infile = open(av[1],O_RDONLY);
		if (pipex->infile < 0)
			bonus_error(0);
		pipex->outfile = open(av[ac - 1], O_CREAT | O_RDWR |O_TRUNC, 0000644);
		if (pipex->outfile < 0)
			bonus_error(1);
	}
	else
	{
		pipex->outfile = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0000644);
		if (pipex->outfile < 0)
			bonus_error(1);
	}
	pipex->cmd_nb = ac - 3 - pipex->here;
    pipex->begin = 2 + pipex->here;
	pipex->path_env = get_path_env(env);
    if (pipex->path_env)
        pipex->path = ft_split(pipex->path_env, ':');
}
void bonus_error(int a)
{
	if (a == 0)
		send_error("Can't open infile\n");
	if (a == 1)
		send_error("Can't open outfile\n");
	if (a == 2)
		send_error("Pipe error\n");
    if (a == 3)
        send_error("Fork error\n");
    perror(" Error ");
	exit(1);
}