/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 21:26:02 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/17 21:51:52 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"

/*
** The ft_isdigit() function tests for a decimal digit character.
** 
** The value of the argument must be representable as an unsigned char
** or the value of EOF.
*/

int	ft_isdigit(int c)
{
	return ((uint8_t)c >= '0' && (uint8_t)c <= '9');
}
