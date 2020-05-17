/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 17:36:05 by amalliar          #+#    #+#             */
/*   Updated: 2020/05/17 03:42:10 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates (with malloc) and returns a substring from the string 'str'.
** The substring begins at index 'start' and is of maximum length 'num'.
*/

char	*ft_substr(const char *str, unsigned int start, size_t num)
{
	char		*little;
	size_t		len;

	if (num == 0)
		return (ft_strdup(""));
	if (str == NULL)
		return (NULL);
	len = ft_strlen(str);
	if (start > len)
		return (NULL);
	len -= start;
	if (len > num)
		len = num;
	if (!(little = (char *)malloc(len + 1)))
		return (NULL);
	ft_memcpy(little, str + start, len);
	little[len] = '\0';
	return (little);
}
