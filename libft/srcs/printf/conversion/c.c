/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 11:47:16 by bmikaeli          #+#    #+#             */
/*   Updated: 2017/04/21 12:00:00 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

void	conversion_big_c(void)
{
	to_wchar(arg_get_wchar());
}

void	conversion_c(void)
{
	if (sgt_printf()->flags.is_long)
		return (conversion_big_c());
	to_char((unsigned char)arg_get_int());
}
