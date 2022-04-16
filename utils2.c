#include"pipex.h"

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && i < n && s1[i] == s2[i])
		i++;
	if (i == n)
		return (1);
	return (0);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1, int j)
{
	char	*str;
	int	i;

	i = 0;
	while (s1[j] && s1[j] != ':')
	{
		j++;
		i++;
	}
	str = (char *)malloc(sizeof(*s1) * (i + 1));
	if (!str)
		return (NULL);
	j = j - i;
	i = 0;
	while (s1[j] && s1[j] != ':')
	{
		str[i] = s1[j];
		i++;
		j++;
	}
	str[i] = 0;
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		x;
	int		xx;

	x = 0;
	xx = 0;
	if (!s1 || !s2)
		return (0);
	new = (char *)malloc(sizeof (char) * (ft_strlen(s1) + ft_strlen(s2)) + 2);
	if (!new)
		return (0);
	while (s1[x] != '\0')
	{
		new[x] = s1[x];
		x++;
	}
	new[x] = '/';
	x++;
	while (s2[xx] != '\0')
	{
		new[x] = s2[xx];
		xx++;
		x++;
	}
	new[x] = '\0';
	return (new);
}

int	ft_strlennn(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}