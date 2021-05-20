/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isxdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 04:43:19 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/17 21:54:03 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"

/*
** The ft_isxdigit() function tests for any hexadecimal-digit character.
** 
** The value of the argument must be representable as an unsigned char
** or the value of EOF.
*/

int	ft_isxdigit(int c)
{
	return (ft_isdigit(c) || \
			((t_uint8)c >= 'a' && (t_uint8)c <= 'f') || \
			((t_uint8)c >= 'A' && (t_uint8)c <= 'F'));
}
