/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 14:00:28 by amalliar          #+#    #+#             */
/*   Updated: 2020/05/01 20:06:28 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Sets the first num bytes of the block of memory pointed by
** ptr to the specified value c (interpreted as an unsigned char).
*/

static inline void		write_block8b(uint64_t *dest, uint64_t *block, \
							size_t *num)
{
	((uint8_t *)*dest)[0] = *block;
	*dest += 1;
	*num -= 1;
}

static inline void		write_block64b(uint64_t *dest, uint64_t *block, \
							size_t *num)
{
	((uint64_t *)*dest)[0] = *block;
	*dest += 8;
	*num -= 8;
}

static inline void		write_block512b(uint64_t *dest, uint64_t *block, \
							size_t *num)
{
	((uint64_t *)*dest)[0] = *block;
	((uint64_t *)*dest)[1] = *block;
	((uint64_t *)*dest)[2] = *block;
	((uint64_t *)*dest)[3] = *block;
	((uint64_t *)*dest)[4] = *block;
	((uint64_t *)*dest)[5] = *block;
	((uint64_t *)*dest)[6] = *block;
	((uint64_t *)*dest)[7] = *block;
	*dest += 64;
	*num -= 64;
}

void					*ft_memset(void *ptr, int c, size_t num)
{
	uint64_t	dest;
	uint64_t	block;

	dest = (uint64_t)ptr;
	if (num >= 8)
	{
		block = (uint8_t)c;
		block |= block << 8;
		block |= block << 16;
		block |= block << 32;
		while (dest % 8)
			write_block8b(&dest, &block, &num);
		while (num >= 64)
			write_block512b(&dest, &block, &num);
		while (num >= 8)
			write_block64b(&dest, &block, &num);
	}
	while (num)
		write_block8b(&dest, &block, &num);
	return (ptr);
}
