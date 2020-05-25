/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 16:22:14 by amalliar          #+#    #+#             */
/*   Updated: 2020/05/24 08:59:56 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"

/*
** Outputs the character 'c' to the given file descriptor.
*/

void	ft_putchar_fd(char c, int fd)
{
	if (write(fd, &c, 1) == -1)
		c = 0;
}
