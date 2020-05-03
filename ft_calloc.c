/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 16:24:15 by amalliar          #+#    #+#             */
/*   Updated: 2020/05/03 16:30:29 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates a block of memory for an array of num elements, each of them
** size bytes long, and initializes all its bits to zero.
*/

void	*ft_calloc(size_t num, size_t size)
{
	size_t		block_size;
	void		*ptr;

	block_size = num * size;
	if (!(ptr = malloc(block_size)))
		return (NULL);
	ft_bzero(ptr, block_size);
	return (ptr);
}
