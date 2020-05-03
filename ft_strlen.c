/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 15:20:17 by amalliar          #+#    #+#             */
/*   Updated: 2020/05/03 16:05:00 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns the length of the C string str. Scan for the null terminator
** quickly by testing eight bytes at a time.
*/

static inline int	test_longword(const uint8_t **char_ptr)
{
	uint8_t		i;

	i = 0;
	while (i < 8)
	{
		if ((*char_ptr)[i] == '\0')
		{
			*char_ptr += i;
			return (1);
		}
		++i;
	}
	return (0);
}

size_t				ft_strlen(const char *str)
{
	const uint8_t		*char_ptr;
	const uint64_t		*longword_ptr;
	uint64_t			longword;
	uint64_t			himagic;
	uint64_t			lomagic;

	char_ptr = (const uint8_t *)str;
	while ((uint64_t)char_ptr % 8 != 0)
		if (*char_ptr == '\0')
			return ((const char *)char_ptr - str);
		else
			++char_ptr;
	longword_ptr = (uint64_t *)char_ptr;
	himagic = 0x8080808080808080;
	lomagic = 0x0101010101010101;
	while (1)
	{
		longword = *longword_ptr++;
		if (((longword - lomagic) & ~longword & himagic) != 0)
		{
			char_ptr = (const uint8_t *)(longword_ptr - 1);
			if (test_longword(&char_ptr))
				return ((const char *)char_ptr - str);
		}
	}
}
