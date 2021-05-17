/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tsuite_ft_ctype.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 22:26:50 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/18 01:31:31 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include "tsuite.h"
#include "tutility.h"
#include "ft_ctype.h"

typedef int	(*t_func)(int);

static void	_ft_ctype_tbatch(t_func lft, t_func lc, char const *batch_name)
{
	print_tbatch_header(batch_name);

	for (int i = 0; i < 256; ++i)
		assert(lft(i) == lc(i));
	printf("%s[OK]%s", GREEN, NOCOLOR);

	assert(lft(EOF) == lc(EOF));
	printf("%s[OK]%s\n", GREEN, NOCOLOR);
}

void	tsuite_ft_ctype(void)
{
	print_tsuite_header("ft_ctype");

	_ft_ctype_tbatch(ft_isalnum, isalnum, "ft_isalnum:");
	_ft_ctype_tbatch(ft_isalpha, isalpha, "ft_isalpha:");
	_ft_ctype_tbatch(ft_isblank, isblank, "ft_isblank:");
	_ft_ctype_tbatch(ft_iscntrl, iscntrl, "ft_iscntrl:");
	_ft_ctype_tbatch(ft_isdigit, isdigit, "ft_isdigit:");
	_ft_ctype_tbatch(ft_isgraph, isgraph, "ft_isgraph:");
	_ft_ctype_tbatch(ft_islower, islower, "ft_islower:");
	_ft_ctype_tbatch(ft_isprint, isprint, "ft_isprint:");
	_ft_ctype_tbatch(ft_ispunct, ispunct, "ft_ispunct:");
	_ft_ctype_tbatch(ft_isspace, isspace, "ft_isspace:");
	_ft_ctype_tbatch(ft_isupper, isupper, "ft_isupper:");
	_ft_ctype_tbatch(ft_isxdigit, isxdigit, "ft_isxdigit:");
	printf("\n");

	_ft_ctype_tbatch(ft_tolower, tolower, "ft_tolower:");
	_ft_ctype_tbatch(ft_toupper, toupper, "ft_toupper:");
	printf("\n");
}
