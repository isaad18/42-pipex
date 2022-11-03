#include"../includes/pipex.h"

int	wordscount(char const *s, char c)
{
	int	i;
	int	words;
	int	flag;

	i = 0;
	words = 0;
	flag = 1;
	while (s[i])
	{
		if (s[i] == c && !flag)
			flag = 1;
		else if (s[i] != c && flag)
		{
			words++;
			flag = 0;
		}
		i++;
	}
	return (words);
}

char	*wordscut(char const *s, int len, int start)
{
	char	*c;
	int		i;

	i = 0;
	c = (char *)malloc(len + 1);
	if (!c)
		return (0);
	while (len > 0)
	{
		c[i++] = s[start - len];
		len--;
	}
	c[i] = '\0';
	return (c);
}

void	wordsplit(char **strs, char c, char const *s, int words)
{
	int	i;
	int	strl;
	int	word;

	i = 0;
	word = 0;
	strl = 0;
	while (word < words)
	{
		while (s[i] && s[i] == c)
			++i;
		while (s[i] != c && s[i])
			if (i++ >= 0)
				strl++;
		strs[word++] = wordscut(s, strl, i);
		strl = 0;
	}
	strs[word] = 0;
}

int	ss(char *s, int i)
{
	while (s[i] && s[i] != ' ')
		i++;
	if (s[i] == ' ')
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**a;
	int		words;

	if (!s)
		return (0);
	words = wordscount(s, c);
	a = (char **)malloc((words + 1) * sizeof(char *));
	if (!a)
		return (0);
	wordsplit(a, c, s, words);
	return (a);
}

// char **echohandle(char const *s)
// {
// 	char	**a;
// 	int		i;
// 	int		j;
// 	char	*c;

// 	a = (char **)malloc((3) * sizeof(char *));
// 	i = 0;
// 	j = 0;
// 	a[0] = "echo";
// 	i = ss(s, i);
// 	while (s[i])
// 	{
// 		i++;
// 		j++;
// 	}
// 	c = malloc(j + 1);
// 	i -= j;
// 	j = 0;
// 	while (s[i])
// 	{
// 		c[j] = s[i];
// 		i++;
// 		j++;
// 	}
// 	c[j] = 0;
// 	a[1] = c;
// 	a[2] = 0;
// 	return (a);
// }