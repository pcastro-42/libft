#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*cur;
	void	*cntt;

	if (!lst || !f || !del)
		return (NULL);
	cntt = f(lst->content);
	new = ft_lstnew(cntt);
	if (!new)
	{
		del(cntt);
		return (NULL);
	}	
	cur = new;
	lst = lst->next;
	while (lst)
	{
		cntt = f(lst->content);
		cur->next = ft_lstnew(cntt);
		cur = cur->next;
		if (!cur)
		{
			del(cntt);
			ft_lstclear(&new, del);
			return (NULL);
		}
		lst = lst->next;
	}
	return (new);
}
