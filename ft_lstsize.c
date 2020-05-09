/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 22:25:04 by amalliar          #+#    #+#             */
/*   Updated: 2020/05/09 20:56:56 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Counts the number of elements in a list.
*/

int		ft_lstsize(t_list *lst)
{
	int		count;

	if (lst == NULL)
		return (0);
	count = 0;
	while (lst != NULL)
	{
		++count;
		lst = lst->next;
	}
	return (count);
}
