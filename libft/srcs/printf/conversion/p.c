/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/21 23:28:08 by bmikaeli          #+#    #+#             */
/*   Updated: 2017/04/19 12:26:48 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

void	conversion_p(void)
{
	const void	*ptr;

	ptr = arg_get_void();
	if (sgt_printf()->flags.prec == 0 && ptr == NULL)
	{
		sgt_printf()->flags.prec = -1;
		sgt_printf()->flags.pad = ' ';
		to_string(ft_strdup("0x"));
		return ;
	}
	sgt_printf()->flags.base = 16;
	sgt_printf()->flags.number.word = (unsigned long int)ptr;
	sgt_printf()->flags.is_negative = false;
	sgt_printf()->flags.alt = true;
	sgt_printf()->flags.spec = 'x';
	number();
}
