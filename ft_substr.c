/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 17:36:05 by amalliar          #+#    #+#             */
/*   Updated: 2020/05/07 17:53:32 by amalliar         ###   ########.fr       */
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

	if (!str)
		return (NULL);
	len = ft_strlen(str + start);
	if (len > num)
		len = num;
	if (!(little = (char *)malloc(len + 1)))
		return (NULL);
	ft_strlcpy(little, str + start, len + 1);
	return (little);
}
