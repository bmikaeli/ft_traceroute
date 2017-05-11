/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_long.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/21 15:47:28 by bmikaeli          #+#    #+#             */
/*   Updated: 2017/04/19 12:28:15 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

unsigned long			arg_get_ulong(void)
{
	return ((unsigned long)va_arg(sgt_printf()->args, unsigned long));
}

long int				arg_get_long_int(void)
{
	return ((long int)va_arg(sgt_printf()->args, long int));
}

unsigned long int		arg_get_ulong_int(void)
{
	return ((unsigned long int)va_arg(sgt_printf()->args, unsigned long int));
}

long long int			arg_get_long_long_int(void)
{
	return ((long long int)va_arg(sgt_printf()->args, long long int));
}

unsigned long long int	arg_get_ulong_long_int(void)
{
	return ((unsigned long long int)va_arg(sgt_printf()->args,
				unsigned long long int));
}
