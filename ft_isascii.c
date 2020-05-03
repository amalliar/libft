/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 21:35:16 by amalliar          #+#    #+#             */
/*   Updated: 2020/05/03 21:36:29 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Checks whether c is a 7-bit unsigned char value that
** fits into the ASCII character set.
*/

int		ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
