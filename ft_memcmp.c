/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 13:55:47 by amalliar          #+#    #+#             */
/*   Updated: 2020/05/03 15:11:54 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Compares the first num bytes of the block of memory pointed by ptr1 to the
** first num bytes pointed by ptr2, returning zero if they all match or a value
** different from zero representing which is greater if they do not.
*/

static inline int	byte_cmp(uint64_t *pt1, uint64_t *pt2, \
						size_t *num)
{
	*pt1 += 1;
	*pt2 += 1;
	*num -= 1;
	return (((uint8_t *)*pt1)[-1] - ((uint8_t *)*pt2)[-1]);
}

static inline int	word_cmp(uint64_t *pt1, uint64_t *pt2, \
						size_t *num)
{
	*pt1 += 8;
	*pt2 += 8;
	*num -= 8;
	return (((uint64_t *)*pt1)[-1] - ((uint64_t *)*pt2)[-1]);
}

int					ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	uint64_t	pt1;
	uint64_t	pt2;
	int			res;

	pt1 = (uint64_t)ptr1;
	pt2 = (uint64_t)ptr2;
	if (num >= 8)
	{
		while (pt1 % 8 != 0)
			if ((res = byte_cmp(&pt1, &pt2, &num)))
				return (res);
		while (num >= 8)
			if ((res = word_cmp(&pt1, &pt2, &num)))
				return (res);
	}
	while (num != 0)
		if ((res = byte_cmp(&pt1, &pt2, &num)))
			return (res);
	return (0);
}
