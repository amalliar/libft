/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 13:19:15 by amalliar          #+#    #+#             */
/*   Updated: 2020/05/03 15:13:32 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Searches within the first num bytes of the block of memory pointed by
** ptr for the first occurrence of c (interpreted as an unsigned char),
** and returns a pointer to it.
*/

static inline void		init_blocks(uint64_t *repeated_one, \
							uint64_t *repeated_c, uint8_t *chr)
{
	*repeated_one = 0x0101010101010101;
	*repeated_c = *chr;
	*repeated_c |= *repeated_c << 8;
	*repeated_c |= *repeated_c << 16;
	*repeated_c |= *repeated_c << 32;
}

static inline void		test_longword(const uint64_t **longword_ptr, \
							size_t *num, uint64_t repeated_c, \
							uint64_t repeated_one)
{
	uint64_t	longword1;

	while (*num >= 8)
	{
		longword1 = **longword_ptr ^ repeated_c;
		if ((((longword1 - repeated_one) & ~longword1) \
			& (repeated_one << 7)) != 0)
			break ;
		++*longword_ptr;
		*num -= 8;
	}
}

void					*ft_memchr(const void *ptr, int c, size_t num)
{
	const uint8_t	*chr_ptr;
	const uint64_t	*longword_ptr;
	uint64_t		repeated_one;
	uint64_t		repeated_c;
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
	init_blocks(&repeated_one, &repeated_c, &chr);
	test_longword(&longword_ptr, &num, repeated_c, repeated_one);
	chr_ptr = (const uint8_t *)longword_ptr;
	while (num-- != 0)
		if (*chr_ptr++ == chr)
			return ((void *)chr_ptr - 1);
	return (NULL);
}
