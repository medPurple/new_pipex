#include "../../include/pipex.h"

static void execute_cmd(t_pipe_b *pipex,char *bla, char **env)
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
        dup2_fd(pipex->pipe_fd_b[1],STDOUT_FILENO);
        close_fd(pipex->pipe_fd_b);
        execute_cmd(pipex,cmd,env);
    }
    else
    {
        dup2_fd(pipex->pipe_fd_b[0],STDIN_FILENO);
        close_fd(pipex->pipe_fd_b);
    }
}

void last_pipe(t_pipe_b *pipex, char *cmd, char **env, char *file)
{
    pipex->outfile = open(file, O_CREAT | O_RDWR |O_TRUNC, 0000644);
    if (pipex->outfile < 0)
	    pipex_error(1);
    if ((pipex->child = fork()) < 0)
	    pipex_error(3);
    dup2_fd(pipex->outfile,STDOUT_FILENO);
    close(pipex->outfile);
    if (pipex->child == 0)
        execute_cmd(pipex,cmd,env);
}