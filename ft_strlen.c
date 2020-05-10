/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 15:20:17 by amalliar          #+#    #+#             */
/*   Updated: 2020/05/10 19:44:50 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef unsigned long	t_longword;

/*
** Returns the length of the C string str. Scan for the null terminator
** quickly by testing eight bytes at a time.
*/

static inline void		init_magic(t_longword *himagic, t_longword *lomagic)
{
	*himagic = 0x80808080;
	*lomagic = 0x01010101;
	if (sizeof(t_longword) > 4)
	{
		*himagic |= (*himagic << 16) << 16;
		*lomagic |= (*lomagic << 16) << 16;
	}
}

/*
**           byte1     byte2          byte8(4)
**
** lomagic:  00000001  00000001  ...  00000001
**
** himagic:  10000000  10000000  ...  10000000
*/

static inline int		test_longword(const unsigned char **char_ptr)
{
	unsigned	i;

	i = 0;
	while (i < sizeof(t_longword))
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

size_t					ft_strlen(const char *str)
{
	const unsigned char		*char_ptr;
	const t_longword		*longword_ptr;
	t_longword				longword;
	t_longword				himagic;
	t_longword				lomagic;

	char_ptr = (const unsigned char *)str;
	while ((size_t)char_ptr % sizeof(t_longword) != 0)
	{
		if (*char_ptr == '\0')
			return ((const char *)char_ptr - str);
		++char_ptr;
	}
	longword_ptr = (t_longword *)char_ptr;
	init_magic(&himagic, &lomagic);
	while (1)
	{
		longword = *longword_ptr++;
		if (((longword - lomagic) & ~longword & himagic) != 0)
		{
			char_ptr = (const unsigned char *)(longword_ptr - 1);
			if (test_longword(&char_ptr))
				return ((const char *)char_ptr - str);
		}
	}
}
