/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshannak <wshannak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 23:56:02 by wshannak          #+#    #+#             */
/*   Updated: 2024/09/15 23:44:35 by wshannak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lstn;
	t_list	*new_node;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	lstn = NULL;
	while (lst)
	{
		content = f(lst->content);
		new_node = ft_lstnew(content);
		if (!new_node)
		{
			if (content)
				del(content);
			ft_lstclear(&lstn, del);
			return (NULL);
		}
		ft_lstadd_back(&lstn, new_node);
		lst = lst->next;
	}
	return (lstn);
}
