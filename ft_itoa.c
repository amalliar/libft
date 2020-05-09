/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 21:49:55 by amalliar          #+#    #+#             */
/*   Updated: 2020/05/09 20:06:08 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates and returns a string representing the
** integer received as an argument.
*/

char	*ft_itoa(int num)
{
	long long	llnum;
	short		digits;
	char		*beg;
	char		*end;

	llnum = num;
	digits = (num == 0) ? 1 : 0;
	while (num != 0)
	{
		++digits;
		num /= 10;
	}
	if (!(beg = (char *)malloc((llnum < 0) + digits + 1)))
		return (NULL);
	*beg = (llnum == 0) ? '0' : '-';
	end = beg + (llnum < 0) + digits;
	*end-- = '\0';
	if (llnum < 0)
		llnum = -llnum;
	while (llnum != 0)
	{
		*end-- = llnum % 10 + '0';
		llnum /= 10;
	}
	return (beg);
}
