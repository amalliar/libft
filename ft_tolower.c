/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 21:49:57 by amalliar          #+#    #+#             */
/*   Updated: 2020/05/03 21:52:06 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Convert uppercase letter to lowercase.
*/

int		ft_tolower(int c)
{
	return ((c >= 'A' && c <= 'Z') ? c - 'A' + 'a' : c);
}