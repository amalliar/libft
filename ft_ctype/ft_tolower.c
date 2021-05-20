/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 21:49:57 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/17 21:54:03 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"

/*
** The ft_tolower() function converts an upper-case letter to the corresponding
** lower-case letter.
**
** The value of the argument must be representable as an unsigned char
** or the value of EOF.
*/

int	ft_tolower(int c)
{
	if (ft_isupper(c))
		return ((t_uint8)c - 'A' + 'a');
	return (c);
}
