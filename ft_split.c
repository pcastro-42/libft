#include "libft.h"

static void	free_all(char **list, int j)
{
	while (j >= 0)
	{
		free(list[j]);
		j--;
	}
}

static int	count_words(char const *s, char c)
{
	int	word_count;
	int	i;
	int	is_delimiter;

	word_count = 0;
	i = 0;
	is_delimiter = 1;
	while (s[i])
	{
		if (s[i] == c)
			is_delimiter = 1;
		else if (is_delimiter)
		{
			word_count++;
			is_delimiter = 0;
		}
		i++;
	}
	return (word_count);
}

static size_t	word_len(char *start, char c)
{
	int	i;

	i = 0;
	while (start[i] && start[i] != c)
	{
		i++;
	}
	return (i);
}

static char	**split(char **list, char const *s, char c, int wc)
{
	int	i;
	int	j;
	int	is_delimiter;
	size_t	len;

	i = 0;
	j = 0;
	is_delimiter = 1;
	while (s[i])
	{
		if (s[i] == c)
			is_delimiter = 1;
		else if (is_delimiter)
		{
			is_delimiter = 0;
			len = word_len(s + i, c);
			list[j] = malloc(sizeof(char) * (len + 1));
			if (!list[j])
			{
				free_all(list, j);
				return (NULL);
			}
			ft_strlcpy(list[j], s + i, len + 1);
			j++;
		}
		i++;
	}
	list[j] = 0;
	return (list);

}

char	**ft_split(char const *s, char c)
{
	int	word_count;
	char	**list;
	char	**res;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	list = malloc(sizeof(char*) * (word_count + 1));
	if (!list)
		return (NULL);
	res = (split(list, s, c, word_count));
	if (!res)
	{
		free(list);
		return (NULL);
	}
	return (res);
}
