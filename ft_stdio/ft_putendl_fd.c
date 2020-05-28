/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 18:13:03 by amalliar          #+#    #+#             */
/*   Updated: 2020/05/28 20:08:45 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"
#include "ft_string.h"

/*
** Outputs the C-string 'str' to the given file descriptor,
** followed by a newline.
*/

void	ft_putendl_fd(char *str, int fd)
{
	if (str == NULL)
		return ;
	(void)write(fd, str, ft_strlen(str));
	(void)write(fd, "\n", 1);
}
