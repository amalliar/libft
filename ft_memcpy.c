/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 18:54:50 by amalliar          #+#    #+#             */
/*   Updated: 2020/05/02 12:26:46 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Copies the values of num bytes from the location pointed to by
** src directly to the memory block pointed to by dest.
*/

static inline void		byte_copy_fwd(uint64_t *dest, uint64_t *src, \
							size_t *num)
{
	((uint8_t *)*dest)[0] = ((uint8_t *)*src)[0];
	*dest += 1;
	*src += 1;
	*num -= 1;
}

static inline void		word_copy_fwd(uint64_t *dest, uint64_t *src, \
							size_t *num)
{
	((uint64_t *)*dest)[0] = ((uint64_t *)*src)[0];
	*dest += 8;
	*src += 8;
	*num -= 8;
}

static inline void		page_copy_fwd(uint64_t *dest, uint64_t *src, \
							size_t *num)
{
	((uint64_t *)*dest)[0] = ((uint64_t *)*src)[0];
	((uint64_t *)*dest)[1] = ((uint64_t *)*src)[1];
	((uint64_t *)*dest)[2] = ((uint64_t *)*src)[2];
	((uint64_t *)*dest)[3] = ((uint64_t *)*src)[3];
	((uint64_t *)*dest)[4] = ((uint64_t *)*src)[4];
	((uint64_t *)*dest)[5] = ((uint64_t *)*src)[5];
	((uint64_t *)*dest)[6] = ((uint64_t *)*src)[6];
	((uint64_t *)*dest)[7] = ((uint64_t *)*src)[7];
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
			byte_copy_fwd(&dest_, &src_, &num);
		while (num >= 64)
			page_copy_fwd(&dest_, &src_, &num);
		while (num >= 8)
			word_copy_fwd(&dest_, &src_, &num);
	}
	while (num)
		byte_copy_fwd(&dest_, &src_, &num);
	return (dest);
}
