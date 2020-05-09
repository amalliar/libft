/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 21:28:39 by amalliar          #+#    #+#             */
/*   Updated: 2020/05/09 19:51:29 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Checks whether c is either a decimal digit or an uppercase
** or lowercase letter.
*/

int		ft_isalnum(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || \
			(c >= '0' && c <= '9'));
}
