/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:53:08 by wmessmer          #+#    #+#             */
/*   Updated: 2023/03/06 19:11:33 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
static void *get_path_env(t_pipe_b *pipex, char **env)
{
	if (!*env)
		return;
	while (*env)
	{
		if (ft_strncmp("PATH", *env, 4) == 0)
		{
			pipex->path = ft_split(*env, ':');
			return;
		}
		env++;
	}
	return;
}
static void	bonus_init(t_pipe_b *pipex, char **env)
{

	pipex->begin = 2 + pipex->here;
    get_path_env_b(env);
}
int	main(int ac, char **av, char **env)
{
	t_pipe_b pipex;
	if (ac < here_or_not((av[1]),&pipex))
		return (send_error("Wrong arg"), 0);
	bonus_init(&pipex, env);
    if(pipex.here == 0)
    {
        pipex.infile = open(av[1],O_RDONLY);
        if (pipex.infile < 0)
            pipex_error(0);
        //dup2_fd(pipex.infile, STDIN_FILENO);
        //close(pipex.infile);
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