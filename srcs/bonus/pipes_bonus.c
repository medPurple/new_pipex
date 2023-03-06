#include "../../include/pipex.h"
static char *search_b(t_pipe *pipex)
{
	char	*tmp;
	char	*command;

	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		command = ft_strjoin(tmp, cmd);
		if (access(command, 0) == 0)
			return (command);
		free(command);
		paths++;
	}
	send_error("command don't exist\n");
	return (NULL);
}
static void execute_cmd_b(t_pipe_b *pipex,char *bla, char **env)
{
	pipex->argument = ft_split(bla, ' ');
	if((ft_strchr(pipex->argument[0], '/') != NULL))
		pipex->cmd = pipex->argument[0];
	else
		pipex->cmd = search(pipex->path, pipex->argument[0]);
	if(execve(pipex->cmd, pipex->argument, env) == -1)
	{
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
	    dup2_fd(pipex->infile, STDIN_FILENO);
		dup2_fd(pipex->pipe_fd_b[1],STDOUT_FILENO);
	    close(pipex->infile);
		close_fd(pipex->pipe_fd_b);
        execute_cmd_b(pipex,cmd,env);
    }
    else
    {
        //dup2_fd(pipex->pipe_fd_b[0],STDIN_FILENO);
		pipex->infile = pipex->pipe_fd_b[0];
		close(pipex->pipe_fd_b[1]);
        //close_fd(pipex->pipe_fd_b);
    }
}

void last_pipe(t_pipe_b *pipex, char *cmd, char **env, char *file)
{
    pipex->outfile = open(file, O_CREAT | O_RDWR |O_TRUNC, 0000644);
    if (pipex->outfile < 0)
	    pipex_error(1);
    if ((pipex->child = fork()) < 0)
	    pipex_error(3);
	dup2_fd(pipex->infile, STDIN_FILENO);
	dup2_fd(pipex->outfile,STDOUT_FILENO);
    close(pipex->outfile);
	close(pipex->infile);
    if (pipex->child == 0)
        execute_cmd_b(pipex,cmd,env);
}