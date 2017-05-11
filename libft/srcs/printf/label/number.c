/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 11:46:27 by bmikaeli          #+#    #+#             */
/*   Updated: 2017/04/21 12:09:27 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

static void			s_alt(void)
{
	if (sgt_printf()->flags.alt && sgt_printf()->flags.base == 16)
	{
		add_char(L'0');
		add_char(sgt_printf()->flags.spec);
	}
	if (sgt_printf()->flags.number.word != 0 && sgt_printf()->flags.alt
		&& sgt_printf()->flags.base == 8)
	{
		add_char('0');
		sgt_printf()->flags.width -= 1;
	}
}

static void			s_flags(void)
{
	if (sgt_printf()->flags.is_negative && sgt_printf()->flags.base == 10)
	{
		add_char('-');
	}
	else if (sgt_printf()->flags.showsign && sgt_printf()->flags.base == 10)
	{
		add_char('+');
	}
	else if (sgt_printf()->flags.space && sgt_printf()->flags.base == 10)
	{
		add_char(' ');
	}
}

static void			s_if_flags(void)
{
	if (sgt_printf()->flags.is_negative && sgt_printf()->flags.base == 10)
		sgt_printf()->flags.width -= 1;
	else if (sgt_printf()->flags.showsign && sgt_printf()->flags.base == 10)
		sgt_printf()->flags.width -= 1;
	else if (sgt_printf()->flags.space && sgt_printf()->flags.base == 10)
		sgt_printf()->flags.width -= 1;
	if (sgt_printf()->flags.alt && sgt_printf()->flags.base == 16)
		sgt_printf()->flags.width -= 2;
	if (sgt_printf()->flags.prec <= (int)ft_strlen(sgt_printf()->work_buffer)
		&& sgt_printf()->flags.alt && sgt_printf()->flags.base == 8)
		sgt_printf()->flags.width -= 1;
}

static void			s_not_left(void)
{
	sgt_printf()->flags.width -= ft_strlen(sgt_printf()->work_buffer)
		+ sgt_printf()->flags.prec;
	s_if_flags();
	if (sgt_printf()->flags.pad == ' ')
	{
		fill_character(' ');
		sgt_printf()->flags.width = 0;
	}
	s_flags();
	s_alt();
	sgt_printf()->flags.width += sgt_printf()->flags.prec;
	fill_character('0');
	add_string(sgt_printf()->work_buffer);
}

void				number(void)
{
	if (sgt_printf()->flags.prec < 0 && sgt_printf()->flags.spec != 'f')
		sgt_printf()->flags.prec = 1;
	else if (sgt_printf()->flags.spec != 'f')
		sgt_printf()->flags.pad = ' ';
	if (sgt_printf()->flags.prec == 0 && sgt_printf()->flags.number.word == 0)
	{
		if ((sgt_printf()->flags.base == 8 && sgt_printf()->flags.alt)
			|| sgt_printf()->flags.spec == 'f'
			|| sgt_printf()->flags.spec == 'b')
			number_type();
	}
	else
	{
		number_type();
	}
	if (sgt_printf()->flags.spec == 'f' && sgt_printf()->flags.alt
		&& sgt_printf()->flags.prec == 0)
		sgt_printf()->work_buffer = concat2(sgt_printf()->work_buffer,
				ft_strlen(sgt_printf()->work_buffer), ".", 1);
	sgt_printf()->flags.prec = ft_max(0, sgt_printf()->flags.prec -
			ft_strlen(sgt_printf()->work_buffer));
	if (sgt_printf()->flags.left == false)
		s_not_left();
	else
		number_left();
}
