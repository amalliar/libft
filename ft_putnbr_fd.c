/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 18:19:35 by amalliar          #+#    #+#             */
/*   Updated: 2020/05/05 14:40:15 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Outputs the integer 'num' to the given file descriptor.
*/

void	ft_putnbr_fd(int num, int fd)
{
	long long	ll_num;
	short		digits;
	char		beg[16];
	char		*end;

	ll_num = num;
	digits = (num == 0) ? 1 : 0;
	while (num != 0)
	{
		++digits;
		num /= 10;
	}
	*beg = (ll_num == 0) ? '0' : '-';
	end = beg + (ll_num < 0) + digits;
	*end-- = '\0';
	num = (ll_num < 0) ? 1 : 0;
	ll_num = (ll_num < 0) ? -ll_num : ll_num;
	while (ll_num != 0)
	{
		*end-- = ll_num % 10 + '0';
		ll_num /= 10;
	}
	write(fd, beg, num + digits);
}
