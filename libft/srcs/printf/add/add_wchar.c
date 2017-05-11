/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_wchar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 22:20:33 by bmikaeli          #+#    #+#             */
/*   Updated: 2017/04/19 12:25:24 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

void	add_wchar(wchar_t c)
{
	if (c <= 0x7F)
		add_char(c);
	else if (c <= 0x7FF)
	{
		add_char((c >> 6) + 0xC0);
		add_char((c & 0x3F) + 0x80);
	}
	else if (c <= 0xFFFF)
	{
		add_char((c >> 12) + 0xE0);
		add_char(((c >> 6) & 0x3F) + 0x80);
		add_char((c & 0x3F) + 0x80);
	}
	else if (c <= 0x10FFFF)
	{
		add_char((c >> 18) + 0xE0);
		add_char(((c >> 12) & 0x3F) + 0x80);
		add_char(((c >> 6) & 0x3F) + 0x80);
		add_char((c & 0x3F) + 0x80);
	}
}
