/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/21 15:46:04 by bmikaeli          #+#    #+#             */
/*   Updated: 2017/04/19 13:25:55 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

char		*arg_get_string(void)
{
	return ((char *)va_arg(sgt_printf()->args, char *));
}

wchar_t		*arg_get_wstring(void)
{
	return ((wchar_t *)va_arg(sgt_printf()->args, wchar_t *));
}
