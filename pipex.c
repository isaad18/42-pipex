#include"pipex.h"

char	*checkpath(char *str, char **env, t_pipex *pip)
{
	char	*cmd;
	char	*path;
	char	*fpath;

	makeit0(pip);
	cmd = NULL;
	cmd = dupcmd(cmd, str);
	findallp(pip, env);
	while (env[pip->i][pip->j])
	{
		path = ft_strdup(env[pip->i], pip->j);
		fpath = ft_strjoin(path, cmd);
		pip->j = nextpath(env, pip->i, pip->j);
		if (access(fpath, F_OK) == 0)
		{
			freecmd(path, cmd);
			return (fpath);
		}
		else
		{
			freefpath(path, fpath);
		}
	}
	checkcmd(env[pip->i][pip->j], cmd, pip);
	return (fpath);
}


int	child1(t_pipex *pip, char **s, char **env, int pid2)
{
	int	i;

	i = 0;
	dup2(pip->fdi, STDIN_FILENO);
	dup2(pip->fd[1], STDOUT_FILENO);
	close(pip->fd[0]);
	close(pip->fdi);
	execve(pip->patharg, s, env);
	waitpid(pid2, NULL, 0);
	while (i < ft_strlennn(s))
	{
		free (s[i]);
		i++;
	}
	free (s);
	return (0);
}

int	child2(t_pipex *pip, char **s, char **env, int	pid1)
{
	int	i;

	i = 0;
	dup2(pip->fdo, STDOUT_FILENO);
	dup2(pip->fd[0], STDIN_FILENO);
	close(pip->fd[1]);
	close(pip->fdo);
	execve(pip->patharg2, s, env);
	waitpid(pid1, NULL, 0);
	close(pip->fdo);
	close(pip->fd[0]);
	close(pip->fd[1]);
	while (i < ft_strlennn(s))
	{
		free (s[i]);
		i++;
	}
	free (s);
	return (pid1);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex pip;

	if (argc == 5)
	{
		pip.fdi = ft_open(argv[1]);
		pip.fdo = ft_open(argv[4]);
		pip.c = 0;
		pip.patharg = checkpath(argv[2], env, &pip);
		pip.c = 1;
		pip.patharg2 = checkpath(argv[3], env, &pip);
		preparing(&pip, argv, env);
	}
	else
		write(STDERR_FILENO, "invalid number of arguments!\n", 29);
	exit(0);
	return (0);
}

void	preparing(t_pipex *pip, char **argv, char **env)
{
	int	pid1;
	int	pid2 = 0;

	pipe(pip->fd);
	pid1 = fork();
	if (pid1 == 0)
		child1(pip, ft_split(argv[2], ' '), env, pid1);
	else
	{
		pid2 = fork();
		if (pid2 == 0)
			child2(pip, ft_split(argv[3], ' '), env, pid2);
	}
	if (access(pip->patharg, F_OK) == 0)
		free(pip->patharg);
	if (access(pip->patharg2, F_OK) == 0)
		free(pip->patharg2);
}