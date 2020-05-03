/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 08:04:18 by amalliar          #+#    #+#             */
/*   Updated: 2020/05/03 21:27:05 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>

void		ft_bzero(void *ptr, size_t num);
void		*ft_memset(void *ptr, int c, size_t num);
void		*ft_memcpy(void *dest, const void *src, size_t num);
void		*ft_memccpy(void *dest, const void *src, int c, size_t num);
void		*ft_memmove(void *dest, const void *src, size_t num);
void		*ft_memchr(const void *ptr, int c, size_t num);
void		*ft_calloc(size_t num, size_t size);
int			ft_memcmp(const void *ptr1, const void *ptr2, size_t num);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
size_t		ft_strlen(const char *str);
size_t		ft_strlcpy(char *dest, const char *src, size_t num);
char		*ft_strdup(const char *str);

#endif
