/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 20:52:32 by amalliar          #+#    #+#             */
/*   Updated: 2020/05/01 20:26:12 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The memccpy() function copies no more than num bytes from memory area src
** to memory area dest, stopping when the character c is found.
*/

void	*ft_memccpy(void *dest, const void *src, int c, size_t num)
{
	void	*ptr;

	ptr = ft_memchr(src, c, num);
	if (ptr != NULL)
	{
		ft_memcpy(dest, src, ptr - src + 1);
		return (dest + (ptr - src + 1));
	}
	ft_memcpy(dest, src, num);
	return (NULL);
}