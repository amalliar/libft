/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isblank.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 03:54:52 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/17 21:50:56 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"

/*
** The ft_isblank() function tests for a space or tab character.
**
** The value of the argument must be representable as an unsigned char
** or the value of EOF.
*/

int	ft_isblank(int c)
{
	return ((uint8_t)c == ' ' || (uint8_t)c == '\t');
}
