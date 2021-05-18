/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst_suite_ft_ctype.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 22:26:50 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/18 08:59:38 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include "ft_ctype.h"
#include "tst_suite.h"
#include "tst_utils.h"

typedef int	(*t_func)(int);
static void	_ft_ctype_batch(t_func fft, t_func flc, char const *batch_name);

void	tst_suite_ft_ctype(void)
{
	tst_print_suite_header("ft_ctype");

	_ft_ctype_batch(ft_isalnum, isalnum, "ft_isalnum:");
	_ft_ctype_batch(ft_isalpha, isalpha, "ft_isalpha:");
	_ft_ctype_batch(ft_isblank, isblank, "ft_isblank:");
	_ft_ctype_batch(ft_iscntrl, iscntrl, "ft_iscntrl:");
	_ft_ctype_batch(ft_isdigit, isdigit, "ft_isdigit:");
	_ft_ctype_batch(ft_isgraph, isgraph, "ft_isgraph:");
	_ft_ctype_batch(ft_islower, islower, "ft_islower:");
	_ft_ctype_batch(ft_isprint, isprint, "ft_isprint:");
	_ft_ctype_batch(ft_ispunct, ispunct, "ft_ispunct:");
	_ft_ctype_batch(ft_isspace, isspace, "ft_isspace:");
	_ft_ctype_batch(ft_isupper, isupper, "ft_isupper:");
	_ft_ctype_batch(ft_isxdigit, isxdigit, "ft_isxdigit:");
	printf("\n");

	_ft_ctype_batch(ft_tolower, tolower, "ft_tolower:");
	_ft_ctype_batch(ft_toupper, toupper, "ft_toupper:");
}

static void	_ft_ctype_batch(t_func fft, t_func flc, char const *batch_name)
{
	tst_print_batch_header(batch_name);

	for (int i = 0; i < 256; ++i)
		assert(fft(i) == flc(i));
	printf("%s[OK]%s", GREEN, NOCOLOR);

	assert(fft(EOF) == flc(EOF));
	printf("%s[OK]%s\n", GREEN, NOCOLOR);
}
