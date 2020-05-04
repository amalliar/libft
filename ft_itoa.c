/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 21:49:55 by amalliar          #+#    #+#             */
/*   Updated: 2020/05/04 23:31:56 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates and returns a string representing the
** integer received as an argument.
*/

char	*ft_itoa(int num)
{
	long long	ll_num;
	short		digits;
	char		*beg;
	char		*end;

	ll_num = num;
	digits = (num == 0) ? 1 : 0;
	while (num != 0)
	{
		++digits;
		num /= 10;
	}
	if (!(beg = (char *)malloc((ll_num < 0) + digits + 1)))
		return (NULL);
	*beg = (ll_num == 0) ? '0' : '-';
	end = beg + (ll_num < 0) + digits;
	*end-- = '\0';
	ll_num = (ll_num < 0) ? -ll_num : ll_num;
	while (ll_num != 0)
	{
		*end-- = ll_num % 10 + '0';
		ll_num /= 10;
	}
	return (beg);
}
