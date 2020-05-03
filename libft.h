/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 08:04:18 by amalliar          #+#    #+#             */
/*   Updated: 2020/05/03 14:04:41 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <stdint.h>

void	ft_bzero(void *ptr, size_t num);
void	*ft_memset(void *ptr, int c, size_t num);
void	*ft_memcpy(void *dest, const void *src, size_t num);
void	*ft_memccpy(void *dest, const void *src, int c, size_t num);
void	*ft_memmove(void *dest, const void *src, size_t num);
void	*ft_memchr(const void *ptr, int c, size_t num);
int		ft_memcmp(const void *ptr1, const void *ptr2, size_t num);

#endif
