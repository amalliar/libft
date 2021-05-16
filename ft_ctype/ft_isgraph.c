/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isgraph.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 04:18:36 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/16 04:22:50 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"

/*
** The ft_isgraph() function tests for any printing character except
** space (` ') and other locale-specific space-like characters.
** 
** The value of the argument must be representable as an unsigned char
** or the value of EOF.
*/

int	ft_isgraph(int c)
{
	return (ft_isprint(c) && !ft_isspace(c));
}
