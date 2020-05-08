/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 21:40:08 by amalliar          #+#    #+#             */
/*   Updated: 2020/05/08 22:01:47 by amalliar         ###   ########.fr       */
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
	t_list	*elem;

	map = NULL;
	while (lst != NULL)
	{
		if (!(elem = ft_lstnew(func(lst->content))))
		{
			ft_lstclear(&map, del);
			return (NULL);
		}
		ft_lstadd_back(&map, elem);
		lst = lst->next;
	}
	return (map);
}
