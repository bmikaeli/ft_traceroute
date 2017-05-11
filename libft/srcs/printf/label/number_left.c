/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_left.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 05:21:32 by bmikaeli          #+#    #+#             */
/*   Updated: 2017/04/21 12:06:09 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

static void		s_alt(void)
{
	if (sgt_printf()->flags.alt && sgt_printf()->flags.base == 16)
	{
		add_char(L'0');
		add_char(sgt_printf()->flags.spec);
		sgt_printf()->flags.width -= 2;
	}
	if (sgt_printf()->flags.number.word != 0 && sgt_printf()->flags.alt
		&& sgt_printf()->flags.base == 8)
	{
		add_char('0');
		sgt_printf()->flags.width -= 1;
	}
}

static void		s_flags(void)
{
	if (sgt_printf()->flags.is_negative && sgt_printf()->flags.base == 10)
	{
		add_char('-');
		sgt_printf()->flags.width -= 1;
	}
	else if (sgt_printf()->flags.showsign && sgt_printf()->flags.base == 10)
	{
		add_char('+');
		sgt_printf()->flags.width -= 1;
	}
	else if (sgt_printf()->flags.space && sgt_printf()->flags.base == 10)
	{
		add_char(' ');
		sgt_printf()->flags.width -= 1;
	}
}

void			number_left(void)
{
	int		temp;

	s_flags();
	s_alt();
	sgt_printf()->flags.width -= ft_strlen(sgt_printf()->work_buffer)
		+ sgt_printf()->flags.prec;
	if (sgt_printf()->flags.prec > 0)
	{
		temp = sgt_printf()->flags.width;
		sgt_printf()->flags.width = sgt_printf()->flags.prec;
		if (sgt_printf()->flags.number.word != 0 && sgt_printf()->flags.alt
			&& sgt_printf()->flags.base == 8)
		{
			sgt_printf()->flags.width -= 1;
			temp += 1;
		}
		fill_character('0');
		sgt_printf()->flags.width = temp;
	}
	add_string(sgt_printf()->work_buffer);
	fill_character(' ');
}
