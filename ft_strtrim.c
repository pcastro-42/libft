#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	if (!*s1)
		return (ft_strdup(""));
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start])
	{
		if (ft_strchr(set, s1[start]))
			start++;
		else
			break ;
	}
	while (end > start)
	{
		if (ft_strchr(set, s1[end]))
			end--;
		else
			break;
	}
	if (end < start)
		str = ft_strdup("");
	else
	{
		str = malloc(sizeof(char) * (end - start + 1 + 1));
		if (!str)
			return (NULL);
		i = 0;
		while (start <= end)
		{
			str[i] = s1[start];
			i++;
			start++;
		}
		str[i] = 0;
	}
	return (str);
}
