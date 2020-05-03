/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 21:44:49 by amalliar          #+#    #+#             */
/*   Updated: 2020/05/03 21:47:19 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Convert lowercase letter to uppercase.
*/

int		ft_toupper(int c)
{
	return ((c >= 'a' && c <= 'z') ? c - 'a' + 'A' : c);
}
