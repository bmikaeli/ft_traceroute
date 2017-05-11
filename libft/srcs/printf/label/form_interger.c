/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_interger.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 20:48:31 by bmikaeli          #+#    #+#             */
/*   Updated: 2017/04/19 12:27:08 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

void	form_interger(void)
{
	long long int	signed_number;

	if (sgt_printf()->flags.is_long)
		signed_number = arg_get_long_int();
	else if (sgt_printf()->flags.is_char)
		signed_number = (signed char)arg_get_uint();
	else if (!sgt_printf()->flags.is_short)
		signed_number = arg_get_int();
	else
		signed_number = (short int)arg_get_uint();
	sgt_printf()->flags.is_negative = signed_number < 0;
	if (sgt_printf()->flags.is_negative)
		sgt_printf()->flags.number.longlong = signed_number * -1;
	else
		sgt_printf()->flags.number.longlong = signed_number;
	number();
}
