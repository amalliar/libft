/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 21:44:49 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/17 21:54:03 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"

/*
** The ft_toupper() function converts a lower-case letter to the corresponding
** upper-case letter.
**
** The value of the argument must be representable as an unsigned char
** or the value of EOF.
*/

int	ft_toupper(int c)
{
	if (ft_islower(c))
		return ((uint8_t)c - 'a' + 'A');
	return (c);
}
