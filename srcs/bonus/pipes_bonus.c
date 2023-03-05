#include "../../include/pipex.h"
static char *kjsdbskdbv(char **paths, char *cmd)
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

static void execute_cmd(t_pipe_b *pipex,char *cmd, char **env)
{
    pipex->argument = ft_split(cmd, ' ');
    if(!ft_strchr(cmd, '/'))
        pipex->cmd = pipex->argument[0];
    else
        pipex->cmd = kjsdbskdbv(pipex->path, pipex->argument[0]);
    if(execve(pipex->cmd, pipex->argument, env) == -1)
    {
        //free
        send_error("Command execution\n");
        exit(1);
    }
}

void first_pipe(t_pipe_b *pipex, char *cmd, char **env)
{
    if (!(pipex->child = fork()))
        bonus_error(3);
    if (pipex->child == 0)
    {
        dup2(pipex->infile,STDIN_FILENO);
        dup2(pipex->pipe_fd_b[1],STDOUT_FILENO);
        close(pipex->pipe_fd_b[0]);
        execute_cmd(pipex, cmd, env);
    }
    else
    {
        dup2(pipex->pipe_fd_b[0],STDIN_FILENO);
        close(pipex->pipe_fd_b[1]);
        waitpid(pipex->child, NULL, 0);
    }
}
void multi_pipe(t_pipe_b *pipex)
{
    if (!(pipex->child = fork()))
        bonus_error(3);
    if (pipex->child == 0)
    {
       dup2(pipex->pipe_fd_b[1],STDOUT_FILENO);
       close(pipex->pipe_fd_b[0]);


        
    }
    else
    {
        dup2(pipex->pipe_fd_b[0],STDIN_FILENO);
        close(pipex->pipe_fd_b[1]);
    }
}

void last_pipe(t_pipe_b *pipex,char *cmd, char **env)
{
    if (!(pipex->child = fork()))
        bonus_error(3);
    if (pipex->child == 0)
    {
        dup2(pipex->outfile,STDOUT_FILENO);
        dup2(pipex->pipe_fd_b[0],STDIN_FILENO);
        close(pipex->pipe_fd_b[1]);
        execute_cmd(pipex, cmd, env);
    }
    else
    {
        dup2(pipex->pipe_fd_b[1],STDOUT_FILENO);
        close(pipex->pipe_fd_b[0]);
        waitpid(pipex->child, NULL, 0);
    }
}