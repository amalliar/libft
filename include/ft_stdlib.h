/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdlib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 07:12:41 by amalliar          #+#    #+#             */
/*   Updated: 2020/05/24 09:13:01 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDLIB_H
# define FT_STDLIB_H
# include <limits.h>
# include <stddef.h>
# include <stdlib.h>

char	*ft_itoa(int num);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t num, size_t size);

#endif
