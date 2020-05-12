/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 18:13:03 by amalliar          #+#    #+#             */
/*   Updated: 2020/05/12 19:40:17 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Outputs the C-string 'str' to the given file descriptor,
** followed by a newline.
*/

void	ft_putendl_fd(char *str, int fd)
{
	if (str == NULL)
		return ;
	if (write(fd, str, ft_strlen(str)) == -1)
		str = NULL;
	if (write(fd, "\n", 1) == -1)
		str = NULL;
}
