/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 03:12:31 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/16 04:42:35 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"

/*
** The ft_isupper() function tests for any upper-case letters.
** 
** The value of the argument must be representable as an unsigned char
** or the value of EOF.
*/

int	ft_isupper(int c)
{
	return ((char)c >= 'A' && (char)c <= 'Z');
}
