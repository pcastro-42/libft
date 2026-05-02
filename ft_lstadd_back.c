#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*res;

	if (!lst)
		return ;
	res = ft_lstlast(*lst);
	if (!res)
	{
		*lst = new;
		return ;
	}
	res->next = new;
}
