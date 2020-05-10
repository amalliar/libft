/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 23:06:02 by amalliar          #+#    #+#             */
/*   Updated: 2020/05/10 17:57:43 by amalliar         ###   ########.fr       */
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
	size_t		len;

	len = ft_strlen(str);
	if (len != 0)
	{
		if (!(*word_tab = (char **)ft_realloc(*word_tab, *tab_size * \
			sizeof(char *), (*tab_size + 1) * sizeof(char *))))
			return (1);
		if (!((*word_tab)[*tab_size] = (char *)malloc(len + 1)))
			return (1);
		ft_memcpy((*word_tab)[*tab_size], str, len);
		(*word_tab)[*tab_size][len] = '\0';
		++*tab_size;
	}
	if (!(*word_tab = (char **)ft_realloc(*word_tab, *tab_size * \
		sizeof(char *), (*tab_size + 1) * sizeof(char *))))
		return (1);
	(*word_tab)[*tab_size] = NULL;
	return (0);
}

static void		*clear_tab(char **word_tab, size_t tab_size)
{
	while (tab_size-- != 0)
		if (word_tab[tab_size] != NULL)
			free(word_tab[tab_size]);
	return (NULL);
}

char			**ft_split(const char *str, char c)
{
	const char		*ptr;
	char			**word_tab;
	size_t			tab_size;

	if (str == NULL || (word_tab = NULL))
		return (NULL);
	tab_size = 0;
	while ((ptr = ft_strchr(str, c)) != NULL)
	{
		if (ptr - str != 0)
		{
			if (!(word_tab = (char **)ft_realloc(word_tab, tab_size * \
				sizeof(char *), (tab_size + 1) * sizeof(char *))))
				return (clear_tab(word_tab, tab_size));
			if (!(word_tab[tab_size] = (char *)malloc(ptr - str + 1)))
				return (clear_tab(word_tab, tab_size));
			ft_memcpy(word_tab[tab_size], str, ptr - str);
			word_tab[tab_size][ptr - str] = '\0';
			++tab_size;
		}
		str = ptr + 1;
	}
	if (null_terminate(str, &word_tab, &tab_size))
		return (clear_tab(word_tab, tab_size));
	return (word_tab);
}
