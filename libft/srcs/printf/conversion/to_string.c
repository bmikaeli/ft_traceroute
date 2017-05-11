/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/21 23:50:42 by bmikaeli          #+#    #+#             */
/*   Updated: 2017/04/19 12:26:55 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

static void		s_trunc(char **s, int length)
{
	int		size;
	int		index;
	char	*string;

	size = (length < 0) ? -length : length;
	string = ft_strnew(size);
	if (*s == NULL)
		return ;
	index = 0;
	while ((*s)[index] && index < size)
	{
		string[index] = (*s)[index];
		++index;
	}
	ft_strdel(s);
	*s = string;
}

void			to_string(char *s)
{
	size_t	len;

	len = ft_strlen(s);
	if (sgt_printf()->flags.prec != -1)
	{
		s_trunc(&s, sgt_printf()->flags.prec);
		len = ft_strlen(s);
	}
	if ((sgt_printf()->flags.width -= len) < 0)
	{
		add_string(s);
		return ;
	}
	if (sgt_printf()->flags.left == false)
		fill_character(sgt_printf()->flags.pad);
	add_string(s);
	if (sgt_printf()->flags.left)
		fill_character(sgt_printf()->flags.pad);
}

void			to_char(char c)
{
	if ((sgt_printf()->flags.width -= 1) < 0)
		return (add_char(c));
	if (sgt_printf()->flags.left == false)
		fill_character(sgt_printf()->flags.pad);
	add_char(c);
	if (sgt_printf()->flags.left)
		fill_character(sgt_printf()->flags.pad);
}

void			to_wchar(wchar_t c)
{
	if ((sgt_printf()->flags.width -= 1) < 0)
		return (add_wchar(c));
	if (sgt_printf()->flags.left == false)
		fill_character(sgt_printf()->flags.pad);
	add_wchar(c);
	if (sgt_printf()->flags.left)
		fill_character(sgt_printf()->flags.pad);
}
