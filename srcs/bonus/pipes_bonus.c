#include "../../include/pipex.h"

static char *search_b(t_pipe_b *pipex)
{
	char	*tmp;
	char	*command;
	int i;

	i = 0;
	if (!(pipex->path))
	{
		ft_free(pipex->argument);
		send_error("ERROR\n No path to search\n");
		exit(EXIT_FAILURE);
	}
	while (pipex->path[i])
	{
		tmp = ft_strjoin(pipex->path[i], "/");
		command = ft_strjoin(tmp, pipex->argument[0]);
		if (access(command, 0) == 0)
			return (command);
		free(command);
		i++;
	}
	free(pipex->path);
	ft_free(pipex->argument);
	send_error("ERROR :\n can't find the cmd\n");
	exit(EXIT_FAILURE);

}
static void execute_cmd_b(t_pipe_b *pipex,char *bla, char **env)
{
	pipex->argument = ft_split(bla, ' ');
	if((ft_strchr(pipex->argument[0], '/') != NULL))
		pipex->cmd = pipex->argument[0];
	else
		pipex->cmd = search_b(pipex);
	if(execve(pipex->cmd, pipex->argument, env) == -1)
	{
		if(pipex->path)
			ft_free(pipex->path);
		ft_free(pipex->argument);
		send_error(" Error : Command execution\n");
		exit(1);
	}
}
void multi_pipe(t_pipe_b *pipex,char *cmd, char **env)
{
    if (pipe(pipex->pipe_fd_b) < 0)
        pipex_error(2);
    if ((pipex->child = fork()) < 0)
	    pipex_error(3);
    if (pipex->child == 0)
    {
		if (pipex->infile < 0)
		{
			if(pipex->path)
				ft_free(pipex->path);
			close_fd(pipex->pipe_fd_b);
			exit(EXIT_FAILURE);
		}
		close(pipex->pipe_fd_b[0]);
	    dup2_fd(pipex->infile, STDIN_FILENO);
		dup2_fd(pipex->pipe_fd_b[1],STDOUT_FILENO);
	    close(pipex->infile);
		close(pipex->pipe_fd_b[1]);
        execute_cmd_b(pipex,cmd,env);
    }
    else
    {
		if(pipex->infile >= 0)
			close(pipex->infile);
		pipex->infile = pipex->pipe_fd_b[0];
		close(pipex->pipe_fd_b[1]);
    }
}

void last_pipe(t_pipe_b *pipex, char *cmd, char **env, char *file)
{
    pipex->outfile = open(file, O_CREAT | O_RDWR |O_TRUNC, 0000644);
    if (pipex->outfile < 0)
	{
		if (pipex->path)
			ft_free(pipex->path);
		close(pipex->infile);
	    pipex_error(1);
	}
	if ((pipex->child = fork()) < 0)
	    pipex_error(3);
    if (pipex->child == 0)
	{
		dup2_fd(pipex->infile, STDIN_FILENO);
		dup2_fd(pipex->outfile,STDOUT_FILENO);
    	close(pipex->outfile);
		close(pipex->infile);
        execute_cmd_b(pipex,cmd,env);
	}
	else
	{
		close(pipex->outfile);
		close(pipex->infile);
	}
}