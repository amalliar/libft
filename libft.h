/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 08:04:18 by amalliar          #+#    #+#             */
/*   Updated: 2020/05/06 23:39:27 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

void		ft_bzero(void *ptr, size_t num);
void		*ft_memset(void *ptr, int c, size_t num);
void		*ft_memcpy(void *dest, const void *src, size_t num);
void		*ft_memccpy(void *dest, const void *src, int c, size_t num);
void		*ft_memmove(void *dest, const void *src, size_t num);
void		*ft_memchr(const void *ptr, int c, size_t num);
void		*ft_calloc(size_t num, size_t size);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *str, int fd);
void		ft_putendl_fd(char *str, int fd);
void		ft_putnbr_fd(int num, int fd);
int			ft_memcmp(const void *ptr1, const void *ptr2, size_t num);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);
int			ft_atoi(const char *str);
int			ft_strncmp(const char *str1, const char *str2, size_t num);
size_t		ft_strlen(const char *str);
size_t		ft_strlcpy(char *dest, const char *src, size_t num);
size_t		ft_strlcat(char *dest, const char *src, size_t num);
char		*ft_strdup(const char *str);
char		*ft_itoa(int num);
char		*ft_strchr(const char *str, int c);
char		*ft_strrchr(const char *str, int c);
char		*ft_strnstr(const char *big, const char *little, size_t num);
char		*ft_strmapi(const char *str, char (*func)(unsigned int, char));
char		**ft_split(const char *str, char c);

#endif
