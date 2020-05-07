/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 08:04:18 by amalliar          #+#    #+#             */
/*   Updated: 2020/05/07 22:25:47 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <limits.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

char				**ft_split(const char *str, char c);
char				*ft_itoa(int num);
char				*ft_strchr(const char *str, int c);
char				*ft_strdup(const char *str);
char				*ft_strjoin(const char *str1, const char *str2);
char				*ft_strmapi(const char *str, \
						char (*func)(unsigned int, char));
char				*ft_strnstr(const char *big, const char *little, \
						size_t num);
char				*ft_strrchr(const char *str, int c);
char				*ft_strtrim(const char *str, const char *set);
char				*ft_substr(const char *str, unsigned int start, size_t num);
int					ft_atoi(const char *str);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_memcmp(const void *ptr1, const void *ptr2, size_t num);
int					ft_strncmp(const char *str1, const char *str2, size_t num);
int					ft_tolower(int c);
int					ft_toupper(int c);
size_t				ft_strlcat(char *dest, const char *src, size_t num);
size_t				ft_strlcpy(char *dest, const char *src, size_t num);
size_t				ft_strlen(const char *str);
void				*ft_calloc(size_t num, size_t size);
void				*ft_memccpy(void *dest, const void *src, int c, size_t num);
void				*ft_memchr(const void *ptr, int c, size_t num);
void				*ft_memcpy(void *dest, const void *src, size_t num);
void				*ft_memmove(void *dest, const void *src, size_t num);
void				*ft_memset(void *ptr, int c, size_t num);
void				ft_bzero(void *ptr, size_t num);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *str, int fd);
void				ft_putnbr_fd(int num, int fd);
void				ft_putstr_fd(char *str, int fd);

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);

#endif
