#ifndef PIPEX_H
# define PIPEX_H

# include<unistd.h>
# include<stdlib.h>
# include<strings.h>
# include<fcntl.h>
# include<errno.h>
# include<stdio.h>
# include<sys/wait.h>

typedef struct s_pipex
{
    int fdi;
    int fdo;
    int fd[2];
    char    *patharg;
    char    *patharg2;
    int c;
}           t_pipex;


char	**ft_split(char const *s, char c);
void    preparing(t_pipex *pipe, char **argv, char **env);
int	ft_strncmp(const char *s1, const char *s2, int n);
int	ft_strlen(const char *s);
char	*ft_strdup(const char *s1, int j);
char	*ft_strjoin(char const *s1, char const *s2);
int	ft_strlennn(char **s);

#endif