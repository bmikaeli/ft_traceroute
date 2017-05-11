/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 15:24:36 by bmikaeli          #+#    #+#             */
/*   Updated: 2017/04/19 13:26:49 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

void	conversion_big_x(void)
{
	sgt_printf()->flags.base = 16;
	sgt_printf()->flags.spec = 'X';
	sgt_printf()->flags.is_negative = 0;
	sgt_printf()->flags.showsign = 0;
	sgt_printf()->flags.space = 0;
	if (sgt_printf()->flags.is_long)
		sgt_printf()->flags.number.longlong = arg_get_ulong_int();
	else if (sgt_printf()->flags.is_char)
		sgt_printf()->flags.number.longlong = arg_get_uchar();
	else
		sgt_printf()->flags.number.longlong = arg_get_uint();
	if (sgt_printf()->flags.number.longlong == 0)
		sgt_printf()->flags.alt = false;
	number();
}

void	conversion_x(void)
{
	sgt_printf()->flags.base = 16;
	sgt_printf()->flags.spec = 'x';
	sgt_printf()->flags.is_negative = 0;
	sgt_printf()->flags.showsign = 0;
	sgt_printf()->flags.space = 0;
	if (sgt_printf()->flags.is_long)
		sgt_printf()->flags.number.longlong = arg_get_ulong_int();
	else if (sgt_printf()->flags.is_char)
		sgt_printf()->flags.number.longlong = arg_get_uchar();
	else
		sgt_printf()->flags.number.longlong = arg_get_uint();
	if (sgt_printf()->flags.number.longlong == 0)
		sgt_printf()->flags.alt = false;
	number();
}
