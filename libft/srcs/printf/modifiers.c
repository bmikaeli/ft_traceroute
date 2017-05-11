/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/21 21:40:01 by bmikaeli          #+#    #+#             */
/*   Updated: 2017/04/21 11:58:43 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

static t_bool	s_modifiers_1(char **s)
{
	if (ft_strnstr(*s, "hh", 2))
	{
		++s;
		sgt_printf()->flags.is_short = false;
		sgt_printf()->flags.is_char = true;
		return (true);
	}
	if (**s == 'h')
	{
		sgt_printf()->flags.is_short = true;
		return (true);
	}
	if (ft_strnstr(*s, "ll", 2))
	{
		++(*s);
		sgt_printf()->flags.is_long_double = true;
		sgt_printf()->flags.is_long = true;
		return (true);
	}
	if (**s == 'l')
	{
		sgt_printf()->flags.is_long = true;
		return (true);
	}
	return (false);
}

static t_bool	s_modifiers_2(char **s)
{
	if (**s == 'z')
	{
		sgt_printf()->flags.is_long_double =
			sizeof(size_t) > sizeof(unsigned long int);
		sgt_printf()->flags.is_long =
			sizeof(size_t) > sizeof(unsigned int);
		return (true);
	}
	if (**s == 'j')
	{
		sgt_printf()->flags.is_long_double =
			sizeof(intmax_t) > sizeof(unsigned long int);
		sgt_printf()->flags.is_long =
			sizeof(intmax_t) > sizeof(unsigned int);
		return (true);
	}
	if (**s == 'L' || **s == 'q')
	{
		sgt_printf()->flags.is_long_double = true;
		sgt_printf()->flags.is_long = true;
		return (true);
	}
	return (false);
}

t_bool			modifiers(char **s)
{
	if (s_modifiers_1(s))
		return (true);
	if (s_modifiers_2(s))
		return (true);
	return (false);
}
