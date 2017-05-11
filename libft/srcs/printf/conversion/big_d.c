/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 14:55:44 by bmikaeli          #+#    #+#             */
/*   Updated: 2017/04/19 13:27:13 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

void	conversion_big_d(void)
{
	long long int	signed_number;

	sgt_printf()->flags.base = 10;
	signed_number = arg_get_long_int();
	sgt_printf()->flags.is_negative = signed_number < 0;
	if (sgt_printf()->flags.is_negative)
	{
		sgt_printf()->flags.number.longlong = signed_number * -1;
	}
	else
	{
		sgt_printf()->flags.number.longlong = signed_number;
	}
	number();
}
