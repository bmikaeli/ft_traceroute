/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_double.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 08:28:43 by bmikaeli          #+#    #+#             */
/*   Updated: 2017/04/19 12:25:38 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

double			arg_get_double(void)
{
	return ((double)va_arg(sgt_printf()->args, double));
}

long double		arg_get_longdouble(void)
{
	return ((long double)va_arg(sgt_printf()->args, long double));
}
