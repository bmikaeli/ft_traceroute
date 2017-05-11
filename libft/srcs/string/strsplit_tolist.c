/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strsplit_tolist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/19 13:09:41 by bmikaeli          #+#    #+#             */
/*   Updated: 2017/04/19 11:48:15 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>
#include <unistd.h>

static size_t	s_len_word(char const *s, char c)
{
	char const	*save;

	save = s;
	while (*s && *s != c)
		++s;
	return (s - save);
}

static size_t	s_count_word(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (s && *s)
	{
		while (*s && *s == c)
			++s;
		if (*s == '\0')
			break ;
		while (*s && *s != c)
			++s;
		++count;
	}
	return (count);
}

t_listd			*ft_strsplit_tolist(char const *s, char c)
{
	int			i;
	int			len_word;
	size_t		count_word;
	t_listd		*list;

	if (!s || !*s)
		return (NULL);
	count_word = s_count_word(s, c);
	list = NULL;
	i = 0;
	while (s && *s)
	{
		while (*s && *s == c)
			++s;
		len_word = s_len_word(s, c);
		if (len_word)
			ft_lstd_push_back(&list, ft_strsub(s, 0, len_word));
		s += len_word;
	}
	return (list);
}
