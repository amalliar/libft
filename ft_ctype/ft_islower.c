/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 03:11:22 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/16 04:29:41 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"

/*
** The ft_islower() function tests for any lower-case letters.
** 
** The value of the argument must be representable as an unsigned char
** or the value of EOF.
*/

int	ft_islower(int c)
{
	return ((char)c >= 'a' && (char)c <= 'z');
}
