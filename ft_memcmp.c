/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 13:55:47 by amalliar          #+#    #+#             */
/*   Updated: 2020/05/09 23:07:23 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef unsigned long	t_longword;

/*
** Compares the first num bytes of the block of memory pointed by ptr1 to the
** first num bytes pointed by ptr2, returning zero if they all match or a value
** different from zero representing which is greater if they do not.
*/

static inline int		byte_cmp(t_longword *pt1, t_longword *pt2, \
							size_t *num)
{
	++*pt1;
	++*pt2;
	--*num;
	return (((unsigned char *)*pt1)[-1] - ((unsigned char *)*pt2)[-1]);
}

int						ft_memcmp(const void *ptr1, const void *ptr2, \
							size_t num)
{
	t_longword		pt1;
	t_longword		pt2;
	int				res;

	pt1 = (t_longword)ptr1;
	pt2 = (t_longword)ptr2;
	if (num >= sizeof(t_longword))
	{
		while (pt1 % sizeof(t_longword) != 0)
			if ((res = byte_cmp(&pt1, &pt2, &num)) != 0)
				return (res);
		while (num >= sizeof(t_longword))
		{
			if (((t_longword *)pt1)[0] != ((t_longword *)pt2)[0])
				break ;
			pt1 += sizeof(t_longword);
			pt2 += sizeof(t_longword);
			num -= sizeof(t_longword);
		}
	}
	while (num != 0)
		if ((res = byte_cmp(&pt1, &pt2, &num)) != 0)
			return (res);
	return (0);
}
