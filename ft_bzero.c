/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 14:00:28 by amalliar          #+#    #+#             */
/*   Updated: 2020/05/01 12:35:18 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Sets the first num bytes of the block of memory
** pointed by ptr to zero.
*/

void	ft_bzero(void *ptr, size_t num)
{
	ft_memset(ptr, 0, num);
}
