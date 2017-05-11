/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/21 16:07:18 by bmikaeli          #+#    #+#             */
/*   Updated: 2017/04/19 12:26:51 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

void	conversion_big_s(void)
{
	wchar_t		*sw;

	sw = arg_get_wstring();
	if (sw == NULL)
		to_string(ft_strdup("(null)"));
	else
		to_string(wstr_to_str(sw));
}

void	conversion_s(void)
{
	char		*s;

	if (sgt_printf()->flags.is_long && !sgt_printf()->flags.is_long_double)
		return (conversion_big_s());
	s = arg_get_string();
	if (s == NULL)
		to_string(ft_strdup("(null)"));
	else
		to_string(ft_strdup(s));
}
