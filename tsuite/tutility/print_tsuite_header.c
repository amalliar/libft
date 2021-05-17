/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tsuite_header.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 23:05:06 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/18 00:22:08 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tutility.h"

void	print_tsuite_header(char const *tsuite_name)
{
	printf("%s==>%s Running test suite for %s...%s\n", GREEN, WHITE, \
		tsuite_name, NOCOLOR);
}
