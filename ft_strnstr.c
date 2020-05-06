/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 19:26:22 by amalliar          #+#    #+#             */
/*   Updated: 2020/05/06 20:39:54 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_strnstr() function locates the first occurrence of the
** null-terminated string little in the string big, where not more
** than num characters are searched.
*/

char	*ft_strnstr(const char *big, const char *little, size_t num)
{
	size_t		little_len;
	size_t		i;

	if (*big && (little_len = ft_strlen(little)) == 0)
		return ((char *)big);
	if (little_len > num)
		return (NULL);
	i = 0;
	while (i <= num - little_len)
	{
		if ((big[0] == little[0]) && !ft_strncmp(big, little, little_len))
			return ((char *)big);
		++big;
		++i;
	}
	return (NULL);
}
