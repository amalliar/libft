/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 00:09:25 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/18 08:45:11 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TST_UTILS_H
# define TST_UTILS_H

# include <assert.h>
# include <stdio.h>
# include "tst_colors.h"

void	tst_print_suite_header(char const *suite_name);
void	tst_print_batch_header(char const *batch_name);

#endif // TST_UTILS_H
