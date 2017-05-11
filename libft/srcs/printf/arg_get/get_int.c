/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/21 15:43:41 by bmikaeli          #+#    #+#             */
/*   Updated: 2017/04/19 12:28:16 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

int				arg_get_int(void)
{
	return ((int)va_arg(sgt_printf()->args, int));
}

unsigned int	arg_get_uint(void)
{
	return ((unsigned int)va_arg(sgt_printf()->args, unsigned int));
}
