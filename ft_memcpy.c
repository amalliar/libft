/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 18:54:50 by amalliar          #+#    #+#             */
/*   Updated: 2020/04/30 19:19:18 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Copies the values of num bytes from the location pointed to by
** src directly to the memory block pointed to by dest.
*/

void	*ft_memcpy(void *dest, const void *src, size_t num)
{
	void	*pdest;

	if (!dest && !src)
		return (dest);
	pdest = dest;
	while (num >= 8)
	{
		*(uint64_t *)pdest = *(uint64_t *)src;
		pdest += 8;
		src += 8;
		num -= 8;
	}
	while (num--)
		*(uint8_t *)pdest++ = *(uint8_t *)src++;
	return (dest);
}
