/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 08:24:04 by bmikaeli          #+#    #+#             */
/*   Updated: 2017/04/19 12:26:34 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

void	conversion_big_f(void)
{
	sgt_printf()->flags.base = 10;
	sgt_printf()->flags.spec = 'f';
	sgt_printf()->flags.number.longdouble = arg_get_double();
	if (sgt_printf()->flags.number.longdouble < 0)
	{
		sgt_printf()->flags.number.longdouble =
			sgt_printf()->flags.number.longdouble * -1;
		sgt_printf()->flags.is_negative = true;
	}
	number();
}

void	conversion_f(void)
{
	sgt_printf()->flags.base = 10;
	sgt_printf()->flags.spec = 'f';
	if (sgt_printf()->flags.is_long)
		return ((void)conversion_big_f());
	else
		sgt_printf()->flags.number.longdouble = arg_get_double();
	if (sgt_printf()->flags.number.longdouble < 0)
	{
		sgt_printf()->flags.number.longdouble =
			sgt_printf()->flags.number.longdouble * -1;
		sgt_printf()->flags.is_negative = true;
	}
	number();
}
