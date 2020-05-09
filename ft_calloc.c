/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 16:24:15 by amalliar          #+#    #+#             */
/*   Updated: 2020/05/09 19:50:23 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates a block of memory for an array of num elements, each of them
** size bytes long, and initializes all its bits to zero.
*/

void	*ft_calloc(size_t num, size_t size)
{
	void		*block;
	size_t		block_size;

	block_size = num * size;
	if (!(block = malloc(block_size)))
		return (NULL);
	ft_memset(block, 0, block_size);
	return (block);
}
