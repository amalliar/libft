/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 16:57:32 by amalliar          #+#    #+#             */
/*   Updated: 2020/05/05 17:32:24 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_strlcat() function appends the NUL-terminated string src to the
** end of dest. It will append at most num - ft_strlen(dest) - 1 bytes,
** NUL-terminating the result.
*/

size_t		ft_strlcat(char *dest, const char *src, size_t num)
{
	size_t		src_len;
	size_t		dest_len;
	size_t		to_copy;

	if (!num)
		return (ft_strlen(src));
	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	if (dest_len > num)
		dest_len = num;
	if (dest_len != num)
	{
		to_copy = num - dest_len - 1;
		if (to_copy > src_len)
			to_copy = src_len;
		dest += dest_len;
		ft_memcpy(dest, src, to_copy);
		dest[to_copy] = '\0';
	}
	return (dest_len + src_len);
}
