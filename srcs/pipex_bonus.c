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
    {
        pipex.infile = open(av[1],O_RDONLY);
        if (pipex.infile < 0)
            bonus_error(0);
        dup2_fd(pipex.infile, STDIN_FILENO);
        close(pipex.infile);
    }
    else
        here_pipe(av[2],&pipex);
    while (pipex.begin < ac - 2)
    {
        multi_pipe(&pipex,av[pipex.begin],env);
        pipex.begin++;
    }
    last_pipe(&pipex,av[pipex.begin],env,av[ac - 1]);
    while (wait(NULL) > 0);
    ft_free(pipex.path);
    return (0);
}