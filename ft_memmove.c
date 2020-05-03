/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 20:29:48 by amalliar          #+#    #+#             */
/*   Updated: 2020/05/03 15:15:39 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_memmove() function copies num bytes from memory area src to
** memory area dest. The memory areas may overlap: copying takes place
** as though the bytes in src are first copied into a temporary array
** that does not overlap src or dest, and the bytes are then copied
** from the temporary array to dest.
*/

static inline void		byte_copy_bwd(uint64_t *dest, uint64_t *src, \
							size_t *num)
{
	*dest -= 1;
	*src -= 1;
	*num -= 1;
	((uint8_t *)*dest)[0] = ((uint8_t *)*src)[0];
}

static inline void		word_copy_bwd(uint64_t *dest, uint64_t *src, \
							size_t *num)
{
	*dest -= 8;
	*src -= 8;
	*num -= 8;
	((uint64_t *)*dest)[0] = ((uint64_t *)*src)[0];
}

void					*ft_memmove(void *dest, const void *src, size_t num)
{
	uint64_t	dest_;
	uint64_t	src_;

	if (!dest && !src)
		return (dest);
	dest_ = (uint64_t)dest;
	src_ = (uint64_t)src;
	if (dest_ - src_ >= num)
		ft_memcpy(dest, src, num);
	else
	{
		dest_ += num;
		src_ += num;
		if (num >= 8)
		{
			while (dest_ % 8 != 0)
				byte_copy_bwd(&dest_, &src_, &num);
			while (num >= 8)
				word_copy_bwd(&dest_, &src_, &num);
		}
		while (num != 0)
			byte_copy_bwd(&dest_, &src_, &num);
	}
	return (dest);
}
