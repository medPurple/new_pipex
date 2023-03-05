#include "../../include/pipex.h"
static char *search(char **paths, char *cmd)
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

void execute_cmd(t_pipe_b *pipex,char *bla, char **env)
{
    pipex->argument = ft_split(bla, ' ');
    if((ft_strchr(pipex->argument[0], '/') != NULL))
        pipex->cmd = pipex->argument[0];
    else
        pipex->cmd = search(pipex->path, pipex->argument[0]);
    if(execve(pipex->cmd, pipex->argument, env) == -1)
    {
        //free
        send_error(" Error : Command execution\n");
        exit(1);
    }
}

void multi_pipe(t_pipe_b *pipex,char *cmd, char **env)
{
    if (pipe(pipex->pipe_fd_b) < 0)
        bonus_error(2);
    if ((pipex->child = fork()) < 0)
        bonus_error(3);
    if (pipex->child == 0)
    {
        dup2(pipex->pipe_fd_b[1],STDOUT_FILENO);
        close(pipex->pipe_fd_b[0]);
        execute_cmd(pipex,cmd,env);
    }
    else
    {
        dup2(pipex->pipe_fd_b[0],STDIN_FILENO);
        close(pipex->pipe_fd_b[1]);
    }
}