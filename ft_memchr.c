/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 13:19:15 by amalliar          #+#    #+#             */
/*   Updated: 2020/05/05 16:53:22 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Searches within the first num bytes of the block of memory pointed by
** ptr for the first occurrence of c (interpreted as an unsigned char),
** and returns a pointer to it.
*/

static inline void		init_magic(uint64_t *lomagic, \
							uint64_t *chmagic, uint8_t *chr)
{
	*lomagic = 0x0101010101010101;
	*chmagic = *chr;
	*chmagic |= *chmagic << 8;
	*chmagic |= *chmagic << 16;
	*chmagic |= *chmagic << 32;
}

static inline void		test_longword(const uint64_t **longword_ptr, \
							size_t *num, uint64_t chmagic, uint64_t lomagic)
{
	uint64_t	longword;
	uint64_t	himagic;

	himagic = 0x8080808080808080;
	while (*num >= 8)
	{
		longword = **longword_ptr ^ chmagic;
		if (((longword - lomagic) & ~longword & himagic) != 0)
			break ;
		++*longword_ptr;
		*num -= 8;
	}
}

void					*ft_memchr(const void *ptr, int c, size_t num)
{
	const uint8_t	*chr_ptr;
	const uint64_t	*longword_ptr;
	uint64_t		lomagic;
	uint64_t		chmagic;
	uint8_t			chr;

	chr = (uint8_t)c;
	chr_ptr = (const uint8_t *)ptr;
	while (num != 0 && (size_t)chr_ptr % 8 != 0)
	{
		if (*chr_ptr == chr)
			return ((void *)chr_ptr);
		++chr_ptr;
		--num;
	}
	longword_ptr = (const uint64_t *)chr_ptr;
	init_magic(&lomagic, &chmagic, &chr);
	test_longword(&longword_ptr, &num, chmagic, lomagic);
	chr_ptr = (const uint8_t *)longword_ptr;
	while (num-- != 0)
		if (*chr_ptr++ == chr)
			return ((void *)chr_ptr - 1);
	return (NULL);
}
