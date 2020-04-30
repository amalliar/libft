/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 14:00:28 by amalliar          #+#    #+#             */
/*   Updated: 2020/04/30 18:14:11 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Sets the first num bytes of the block of memory pointed by
** ptr to the specified value (interpreted as an unsigned char).
*/

void	*ft_memset(void *ptr, int value, size_t num)
{
	void		*buf;
	uint8_t		byte;
	uint64_t	block;

	buf = ptr;
	byte = (uint8_t)value;
	if (num >= 8)
	{
		block = byte;
		block |= block << 8;
		block |= block << 16;
		block |= block << 32;
		while (num >= 8)
		{
			*(uint64_t *)buf = block;
			buf += 8;
			num -= 8;
		}
	}
	while (num-- != 0)
		*(uint8_t *)buf++ = byte;
	return (ptr);
}
