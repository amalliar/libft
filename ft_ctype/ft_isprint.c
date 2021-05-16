/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 21:38:10 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/16 04:35:00 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"

/*
** The ft_isprint() function tests for any printing character,
** including space (` ').
** 
** The value of the argument must be representable as an unsigned char
** or the value of EOF.
*/

int	ft_isprint(int c)
{
	return ((char)c > 0x1f && (char)c != 0x7f);
}
