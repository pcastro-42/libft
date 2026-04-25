
#include "libft.h"

char  *ft_substr(char const *s, unsigned int start, size_t len)
{
  char  *s2;
  size_t  i;

  if (start > ft_strlen(s))
    return (ft_strdup(""));
  len = ft_strlen(s + start);
  s2 = malloc((len + 1) * sizeof(char));
  if (s2 == (void*)0)
    return ((void*)0);
  i = 0;
  while (i < len)
  {
    s2[i] = s[i + start];
    i++;
  }
  s2[i] = 0;
  return (s2);
}
