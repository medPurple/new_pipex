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
    (void)av;
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
    if (a == 4)
        send_error("Close error\n");
    if (a == 5)
        send_error("Dup2 error\n");
    perror(" Error ");
	exit(1);
}