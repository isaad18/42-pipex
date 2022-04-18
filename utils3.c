#include"pipex.h"

int	ft_open(char *str)
{
	int	fd;

	fd = open(str, O_RDWR | O_CREAT | O_TRUNC);
	if (fd == -1)
	{
		write(1, "invalid fd\n", 11);
		exit(1);
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

void	checkcmd(char c, char *cmd, t_pipex *pip)
{
	if (c == '\0')
	{
		free(cmd);
		if (pip->c && pip->patharg[0] == '/')
			free(pip->patharg);
		write (1, "zsh: command not found!", 23);
		exit (127);
	}
}

void makeit0(t_pipex *pip)
{
	pip->i = 0;
	pip->j = 0;
}

int	nextpath(char **ev, int i, int j)
{
	while (ev[i][j] && ev[i][j] != ':')
			j++;
	if (ev[i][j] != '\0' && ev[i][j] == ':')
		j++;
	return (j);
}
