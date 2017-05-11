/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:26:50 by bmikaeli          #+#    #+#             */
/*   Updated: 2017/04/19 12:26:59 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

void	conversion_u(void)
{
	sgt_printf()->flags.base = 10;
	sgt_printf()->flags.is_negative = 0;
	sgt_printf()->flags.showsign = 0;
	sgt_printf()->flags.space = 0;
	if (sgt_printf()->flags.is_long)
		sgt_printf()->flags.number.longlong = arg_get_ulong_int();
	else if (sgt_printf()->flags.is_char)
		sgt_printf()->flags.number.longlong = (unsigned char)arg_get_uint();
	else if (!sgt_printf()->flags.is_short)
		sgt_printf()->flags.number.longlong = arg_get_uint();
	else
		sgt_printf()->flags.number.longlong =
			(unsigned short int)arg_get_uint();
	number();
}

void	conversion_big_u(void)
{
	sgt_printf()->flags.base = 10;
	sgt_printf()->flags.is_negative = 0;
	sgt_printf()->flags.showsign = 0;
	sgt_printf()->flags.space = 0;
	sgt_printf()->flags.number.longlong = arg_get_ulong_int();
	number();
}
