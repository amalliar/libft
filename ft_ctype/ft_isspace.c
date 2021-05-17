/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 20:42:35 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/17 21:54:03 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"

/*
** The ft_isspace() function tests for the white-space characters.
** For any locale, this includes the following standard characters:
** ``\t''   ``\n''    ``\v''    ``\f''    ``\r''    `` ''
**
** The value of the argument must be representable as an unsigned char
** or the value of EOF.
*/

int	ft_isspace(int c)
{
	return (((uint8_t)c >= '\t' && (uint8_t)c <= '\r') || (uint8_t)c == ' ');
}
