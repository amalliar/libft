/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctype.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 07:26:04 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/17 21:49:38 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CTYPE_H
# define FT_CTYPE_H

# include <stdint.h>

/*
** These functions take the int equivalent of one character as parameter and
** return an int that can either be another character or a value representing
** a boolean value: an int value of 0 means false, and an int value different
** from 0 represents true.
*/

/*
** Character classification functions
*/

int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isblank(int c);
int		ft_iscntrl(int c);
int		ft_isdigit(int c);
int		ft_isgraph(int c);
int		ft_islower(int c);
int		ft_isprint(int c);
int		ft_ispunct(int c);
int		ft_isspace(int c);
int		ft_isupper(int c);
int		ft_isxdigit(int c);

/*
** Character conversion functions
*/

int		ft_tolower(int c);
int		ft_toupper(int c);

#endif
