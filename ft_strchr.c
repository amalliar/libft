/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 14:52:18 by amalliar          #+#    #+#             */
/*   Updated: 2020/05/05 16:13:10 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns a pointer to the first occurrence of character
** in the C string str.
*/

static inline void		init_magic(uint64_t *himagic, uint64_t *lomagic, \
							uint64_t *chmagic, uint8_t chr)
{
	*himagic = 0x8080808080808080;
	*lomagic = 0x0101010101010101;
	*chmagic = chr;
	*chmagic |= *chmagic << 8;
	*chmagic |= *chmagic << 16;
	*chmagic |= *chmagic << 32;
}

static inline int		test_longword(char **char_ptr, char c)
{
	int		i;

	i = 0;
	while (i < 8)
	{
		if ((*char_ptr)[i] == c)
		{
			*char_ptr += i;
			return (1);
		}
		else if ((*char_ptr)[i] == '\0')
		{
			*char_ptr = NULL;
			return (1);
		}
		++i;
	}
	return (0);
}

char					*ft_strchr(char *str, int c)
{
	const uint64_t	*longword_ptr;
	uint64_t		longword;
	uint64_t		himagic;
	uint64_t		lomagic;
	uint64_t		chmagic;

	while ((size_t)str % 8 != 0)
		if (*str == (char)c)
			return (str);
		else if (*str++ == '\0')
			return (NULL);
	longword_ptr = (const uint64_t *)str;
	init_magic(&himagic, &lomagic, &chmagic, c);
	while (1)
	{
		longword = *longword_ptr++;
		if (((longword - lomagic) & ~longword & himagic) != 0 || \
			(((longword ^ chmagic) - lomagic) & ~longword & himagic) != 0)
		{
			str = (char *)(longword_ptr - 1);
			if (test_longword(&str, c))
				return (str);
		}
	}
}
