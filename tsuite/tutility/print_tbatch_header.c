/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tbatch_header.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 23:12:49 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/18 01:09:24 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tutility.h"

void	print_tbatch_header(char const *tbatch_name)
{
	printf("  %s->%s Testing %-16s ", BLUE, NOCOLOR, tbatch_name);
}
