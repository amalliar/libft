/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst_print_suite_header.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 23:05:06 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/18 08:48:05 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tst_utils.h"

void	tst_print_suite_header(char const *suite_name)
{
	printf("%s==>%s Running test suite for %s...%s\n", GREEN, WHITE, \
		suite_name, NOCOLOR);
}
