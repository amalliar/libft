/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 21:40:08 by amalliar          #+#    #+#             */
/*   Updated: 2020/05/09 20:53:28 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Iterates the list 'lst' and applies the function 'func' to the
** content of each element. Creates a new list resulting of the
** successive applications of the function 'func'. The 'del'
** function is used to delete the content of an element if needed.
*/

t_list		*ft_lstmap(t_list *lst, void *(*func)(void *), void (*del)(void *))
{
	t_list	*map;
	t_list	*tail;
	t_list	*elem;

	map = NULL;
	if (lst != NULL)
	{
		if (!(elem = ft_lstnew(func(lst->content))))
			return (NULL);
		ft_lstadd_back(&map, elem);
		tail = map;
		lst = lst->next;
	}
	while (lst != NULL)
	{
		if (!(elem = ft_lstnew(func(lst->content))))
		{
			ft_lstclear(&map, del);
			return (NULL);
		}
		ft_lstadd_back(&tail, elem);
		tail = tail->next;
		lst = lst->next;
	}
	return (map);
}
