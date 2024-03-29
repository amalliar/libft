/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iscntrl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 04:04:17 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/17 21:51:31 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"

/*
** The ft_iscntrl() function tests for any control character.
**
** The value of the argument must be representable as an unsigned char
** or the value of EOF.
*/

int	ft_iscntrl(int c)
{
	return (((t_uint8)c >= 0x00 && (t_uint8)c <= 0x1f) || (t_uint8)c == 0x7f);
}
