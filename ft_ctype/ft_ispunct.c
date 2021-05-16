/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ispunct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 04:33:39 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/16 04:37:22 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"

/*
** The ft_ispunct() function tests for any printing character,
** except for space (` ') or a character for which ft_isalnum() is true.
**
** The value of the argument must be representable as an unsigned char
** or the value of EOF.
*/

int	ft_ispunct(int c)
{
	return (ft_isgraph(c) && !ft_isalnum(c));
}
