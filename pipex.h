#ifndef PIPEX_H
# define PIPEX_H

# include<errno.h>
# include<stdio.h>
# include<fcntl.h>
# include<unistd.h>
# include<stdlib.h>
# include<strings.h>
# include<sys/wait.h>

typedef struct s_pipex
{
	int		i;
	int		j;
	int		c;
	int		fdi;
	int		fdo;
	int		fd[2];
	char	*patharg;
	char	*patharg2;
}		   t_pipex;


int		ft_open(char *str);
void	makeit0(t_pipex *pip);
int		ft_strlennn(char **s);
int		ft_strlen(const char *s);
char	*dupcmd(char *cmd, char *str);
void	freecmd(char *path, char*cmd);
char	*ft_strdup(const char *s1, int j);
char	**ft_split(char const *s, char c);
int		nextpath(char **ev, int i, int j);
void	freefpath(char *path, char* fpath);
void	findallp(t_pipex *pip, char **env);
void	checkcmd(char c, char *cmd, t_pipex *pip);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, int n);
void	preparing(t_pipex *pipe, char **argv, char **env);

#endif