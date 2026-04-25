#include "libft.h"

char    *ft_strjoin(char const *s1, char const *s2)
{
    size_t    len;
    char    *dest;
    char    *cur;    

    len = ft_strlen(s1) + ft_strlen(s2);
    dest = malloc((len + 1) * sizeof(char));
    if (!dest)
        return (void*(0));
    cur = dest;
	while (*s1)
    {
		*cur = *s1;
        s1++;
		cur++;
    }
	while (*s2)
	{
		*cur = *s2;
		s2++;
		cur++;
	}
	*cur = 0;
	return (dest);
}
