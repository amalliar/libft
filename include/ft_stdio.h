/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdio.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 07:45:23 by amalliar          #+#    #+#             */
/*   Updated: 2020/06/03 20:01:50 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDIO_H
# define FT_STDIO_H
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_get_next_line(int fd, char **line);
int		ft_putchar_fd(int c, int fd);
int		ft_putendl_fd(char *str, int fd);
int		ft_putnbr_fd(int num, int fd);
int		ft_putstr_fd(char *str, int fd);

#endif
