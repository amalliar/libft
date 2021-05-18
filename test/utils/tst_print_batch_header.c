/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst_print_batch_header.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 23:12:49 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/18 08:46:58 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tst_utils.h"

void	tst_print_batch_header(char const *batch_name)
{
	printf("  %s->%s Testing %-16s ", BLUE, NOCOLOR, batch_name);
}
