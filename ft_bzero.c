/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 14:00:28 by amalliar          #+#    #+#             */
/*   Updated: 2020/04/30 18:49:08 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Sets the first num bytes of the block of memory
** pointed by ptr to zero.
*/

void	ft_bzero(void *ptr, size_t num)
{
	while (num >= 8)
	{
		*(uint64_t *)ptr = 0;
		ptr += 8;
		num -= 8;
	}
	while (num--)
		*(uint8_t *)ptr++ = 0;
}
