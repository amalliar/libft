/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 18:04:33 by amalliar          #+#    #+#             */
/*   Updated: 2020/05/24 09:04:43 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"
#include "ft_string.h"

/*
** Outputs the C-string 'str' to the given file descriptor.
*/

void	ft_putstr_fd(char *str, int fd)
{
	if (str == NULL)
		return ;
	if (write(fd, str, ft_strlen(str)) == -1)
		str = NULL;
}
