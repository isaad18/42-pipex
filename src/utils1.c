#include"../includes/pipex.h"

void	freecmd(char *path, char*cmd)
{
	free (cmd);
	free (path);
}

void	freefpath(char *path, char* fpath)
{
	free (fpath);
	free (path);
}

void	findallp(t_pipex *pip, char **env)
{
	while (env[pip->i] && ft_strncmp("PATH=", env[pip->i], 5) == 0)
		pip->i++;
	while (env[pip->i][pip->j] != '/')
		pip->j++;
}
