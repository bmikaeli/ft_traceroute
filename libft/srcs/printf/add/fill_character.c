/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_character.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/21 22:59:37 by bmikaeli          #+#    #+#             */
/*   Updated: 2017/04/19 12:25:28 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

void	fill_character(char c)
{
	while (sgt_printf()->flags.width > 0)
	{
		add_char(c);
		--sgt_printf()->flags.width;
	}
}
