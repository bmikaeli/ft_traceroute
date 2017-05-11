/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 15:01:08 by bmikaeli          #+#    #+#             */
/*   Updated: 2017/04/19 13:27:02 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

void	conversion_big_o(void)
{
	long long int	signed_number;

	sgt_printf()->flags.base = 8;
	signed_number = arg_get_ulong_int();
	sgt_printf()->flags.number.longlong = signed_number;
	number();
}

void	conversion_o(void)
{
	sgt_printf()->flags.base = 8;
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
