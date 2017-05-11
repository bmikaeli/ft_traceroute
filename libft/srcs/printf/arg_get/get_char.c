/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/21 15:45:19 by bmikaeli          #+#    #+#             */
/*   Updated: 2017/04/19 12:25:34 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

char			arg_get_char(void)
{
	return ((char)arg_get_int());
}

unsigned char	arg_get_uchar(void)
{
	return ((unsigned char)arg_get_int());
}

wchar_t			arg_get_wchar(void)
{
	return ((wchar_t)va_arg(sgt_printf()->args, wchar_t));
}
