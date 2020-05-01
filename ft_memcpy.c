/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 18:54:50 by amalliar          #+#    #+#             */
/*   Updated: 2020/05/01 13:10:15 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Copies the values of num bytes from the location pointed to by
** src directly to the memory block pointed to by dest.
*/

static inline void		write_block1B(uint64_t *dest, uint64_t *src, size_t *num)
{
	((uint8_t *)*dest)[0] = ((uint8_t *)*src)[0];
	*dest += 1;
	*src += 1;
	*num -= 1;
}

static inline void		write_block8B(uint64_t *dest, uint64_t *src, size_t *num)
{
	((uint64_t *)*dest)[0] = ((uint64_t *)*src)[0];
	*dest += 8;
	*src += 8;
	*num -= 8;
}

static inline void		write_block64B(uint64_t *dest, uint64_t *src, size_t *num)
{
	((uint64_t *)*dest)[0] = ((uint64_t *)*src)[0];
	((uint64_t *)*dest)[0] = ((uint64_t *)*src)[1];
	((uint64_t *)*dest)[0] = ((uint64_t *)*src)[2];
	((uint64_t *)*dest)[0] = ((uint64_t *)*src)[3];
	((uint64_t *)*dest)[0] = ((uint64_t *)*src)[4];
	((uint64_t *)*dest)[0] = ((uint64_t *)*src)[5];
	((uint64_t *)*dest)[0] = ((uint64_t *)*src)[6];
	((uint64_t *)*dest)[0] = ((uint64_t *)*src)[7];
	*dest += 64;
	*src += 64;
	*num -= 64;
}

void					*ft_memcpy(void *dest, const void *src, size_t num)
{
	uint64_t	dest_;
	uint64_t	src_;

	if (!dest && !src)
		return (dest);
	dest_ = (uint64_t)dest;
	src_ = (uint64_t)src;
	if (num >= 8)
	{
		while (dest_ % 8)
			write_block1B(&dest_, &src_, &num);
		while (num >= 64)
			write_block64B(&dest_, &src_, &num);
		while (num >= 8)
			write_block8B(&dest_, &src_, &num);
	}
	while (num)
		write_block1B(&dest_, &src_, &num);
	return (dest);
}
