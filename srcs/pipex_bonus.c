/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:53:08 by wmessmer          #+#    #+#             */
/*   Updated: 2023/02/20 10:09:28 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int ac, char **av, char **env)
{
	t_pipe_b pipex;
	if (ac < here_or_not((av[1]),&pipex))
		return (send_error("Wrong arg"), 0);
	bonus_init(av,ac,&pipex, env);
    /*first_pipe(&pipex, av[pipex.begin],env);
    while (pipex.begin < ac - 2)
    {
        if (!(pipe(pipex.pipe_fd_b)))
            bonus_error(2);
        multi_pipe();
    }
    last_pipe(&pipex,av[pipex.begin],env);*/
    return (0);
}