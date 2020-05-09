/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 23:06:02 by amalliar          #+#    #+#             */
/*   Updated: 2020/05/09 19:34:47 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates (with malloc) and returns an array of strings
** obtained by splitting 'str' using the character 'c' as
** a delimiter. The array must be ended by a NULL pointer.
*/

static void		*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*tmp;

	if (!(tmp = malloc(new_size)))
	{
		if (old_size != 0)
			free(ptr);
		return (NULL);
	}
	if (old_size != 0)
	{
		if (new_size > old_size)
			ft_memcpy(tmp, ptr, old_size);
		else
			ft_memcpy(tmp, ptr, new_size);
		free(ptr);
	}
	return (tmp);
}

static int		null_terminate(const char *str, char ***word_tab, \
					size_t *tab_size)
{
	const char		*ptr;

	if ((ptr = str + ft_strlen(str)) != str)
	{
		if (!(*word_tab = (char **)ft_realloc(*word_tab, *tab_size * \
			sizeof(char *), (*tab_size + 1) * sizeof(char *))))
			return (1);
		if (!((*word_tab)[*tab_size] = (char *)malloc(ptr - str + 1)))
			return (1);
		ft_memcpy((*word_tab)[*tab_size], str, ptr - str);
		(*word_tab)[*tab_size][ptr - str] = '\0';
		++*tab_size;
	}
	if (!(*word_tab = (char **)ft_realloc(*word_tab, *tab_size * \
		sizeof(char *), (*tab_size + 1) * sizeof(char *))))
		return (1);
	(*word_tab)[*tab_size] = NULL;
	return (0);
}

char			**ft_split(const char *str, char c)
{
	const char		*ptr;
	char			**word_tab;
	size_t			tab_size;

	if (!str || (word_tab = NULL))
		return (NULL);
	tab_size = 0;
	while ((ptr = ft_strchr(str, c)) != NULL)
	{
		if (ptr - str != 0)
		{
			if (!(word_tab = (char **)ft_realloc(word_tab, tab_size * \
				sizeof(char *), (tab_size + 1) * sizeof(char *))))
				return (NULL);
			if (!(word_tab[tab_size] = (char *)malloc(ptr - str + 1)))
				return (NULL);
			ft_memcpy(word_tab[tab_size], str, ptr - str);
			word_tab[tab_size][ptr - str] = '\0';
			++tab_size;
		}
		str = ptr + 1;
	}
	if (null_terminate(str, &word_tab, &tab_size))
		return (NULL);
	return (word_tab);
}
