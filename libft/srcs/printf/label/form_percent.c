/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 12:30:22 by bmikaeli          #+#    #+#             */
/*   Updated: 2017/04/19 12:27:12 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

void	form_percent(void)
{
	sgt_printf()->flags.prec = -1;
	to_string(ft_strdup("%"));
}
