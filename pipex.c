#include"pipex.h"

int	ft_open(char *str)
{
	int	fd;

	fd = open(str, O_RDWR | O_CREAT | O_TRUNC);
	if (fd == -1)
	{
		write(1, "invalid fd\n", 11);
		exit(-1);
	}
	return (fd);
}

char	*dupcmd(char *cmd, char *str)
{
	int	i;

	i = 0;
	while (str[i] != ' ' && str[i])
		i++;
	cmd = malloc(i + 2);
	i = 0;
	while (str[i] != ' ' && str[i])
	{
		cmd[i] = str[i];
		i++;
	}
	cmd[i] = '\0';
	return (cmd);
}

char	*checkpath(char *str, char **env, t_pipex *pip)
{
	char	*cmd;
	char	*path;
	char	*fpath;

	int	i;
	int	j;

	i = 0;
	j = 0;
	cmd = NULL;
	cmd = dupcmd(cmd, str);
	while (env[i] && ft_strncmp("PATH=", env[i], 5) == 0)
		i++;
	while (env[i][j] != '/')
		j++;
	while (env[i][j])
	{
		path = ft_strdup(env[i], j);
		fpath = ft_strjoin(path, cmd);
		while (env[i][j] && env[i][j] != ':')
			j++;
		if (env[i][j] != '\0' && env[i][j] == ':')
			j++;
		if (access(fpath, F_OK) == 0)
		{
			free(path);
			free(cmd);
			return (fpath);
		}
		else
		{
			free(path);
			free(fpath);
		}
	}
	if (env[i][j] == '\0')
	{
		free(cmd);
		if (pip->c && pip->patharg[0] == '/')
			free(pip->patharg);
		exit (0);
	}
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