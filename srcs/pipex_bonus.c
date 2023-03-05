/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:53:08 by wmessmer          #+#    #+#             */
/*   Updated: 2023/03/05 22:12:01 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int ac, char **av, char **env)
{
	t_pipe_b pipex;
	if (ac < here_or_not((av[1]),&pipex))
		return (send_error("Wrong arg"), 0);
	bonus_init(av,ac,&pipex, env);
    if(pipex.here == 0)
        dup2(pipex.infile, STDIN_FILENO);
    else
        here_pipe(av[2],&pipex);
    while (pipex.begin < ac - 2)
    {
        if (pipe(pipex.pipe_fd_b) < 0)
            bonus_error(2);
        multi_pipe(&pipex,av[pipex.begin],env);
        pipex.begin++;
    }
    dup2(pipex.outfile,STDOUT_FILENO);
    execute_cmd(&pipex, av[pipex.begin], env);
    return (0);
}