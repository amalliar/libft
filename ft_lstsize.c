/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 22:25:04 by amalliar          #+#    #+#             */
/*   Updated: 2020/05/07 22:28:13 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Counts the number of elements in a list.
*/

int		ft_lstsize(t_list *lst)
{
	int		count;

	if (!lst)
		return (0);
	count = 1;
	while (lst->next != NULL)
	{
		++count;
		lst = lst->next;
	}
	return (count);
}
