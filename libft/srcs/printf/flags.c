/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/21 20:50:52 by bmikaeli          #+#    #+#             */
/*   Updated: 2017/04/19 12:27:35 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

static t_bool	s_flags_1(char **s)
{
	if (**s == ' ')
	{
		sgt_printf()->flags.space = true;
		return (true);
	}
	if (**s == '+')
	{
		sgt_printf()->flags.showsign = true;
		return (true);
	}
	if (**s == '-')
	{
		sgt_printf()->flags.pad = ' ';
		sgt_printf()->flags.left = true;
		return (true);
	}
	if (**s == '#')
	{
		sgt_printf()->flags.alt = true;
		return (true);
	}
	return (false);
}

static t_bool	s_flags_2(char **s)
{
	if (**s == '*')
	{
		sgt_printf()->flags.width = arg_get_int();
		if (sgt_printf()->flags.width < 0)
		{
			sgt_printf()->flags.width = -sgt_printf()->flags.width;
			sgt_printf()->flags.pad = ' ';
			sgt_printf()->flags.left = true;
		}
		++(*s);
		if (ft_isdigit(**s))
		{
			sgt_printf()->flags.width = ft_atoi(*s);
			while (ft_isdigit(**s))
				++(*s);
		}
		--(*s);
		return (true);
	}
	return (false);
}

static t_bool	s_flags_3(char **s)
{
	if (**s == '.')
	{
		++(*s);
		if (**s == '*')
		{
			sgt_printf()->flags.prec = arg_get_int();
			if (sgt_printf()->flags.prec < 0)
				sgt_printf()->flags.prec = -1;
			return (true);
		}
		if (ft_isdigit(**s))
		{
			sgt_printf()->flags.prec = ft_atoi(*s);
			while (ft_isdigit(**s))
				++(*s);
			--(*s);
		}
		else
		{
			sgt_printf()->flags.prec = 0;
			--(*s);
		}
		return (true);
	}
	return (false);
}

static t_bool	s_flags_4(char **s)
{
	if (**s == '0')
	{
		if (sgt_printf()->flags.left == false)
			sgt_printf()->flags.pad = '0';
		return (true);
	}
	if (ft_isdigit(**s))
	{
		sgt_printf()->flags.width = ft_atoi(*s);
		while (ft_isdigit(**s))
			++(*s);
		--(*s);
		return (true);
	}
	return (false);
}

t_bool			flags(char **s)
{
	if (s_flags_1(s))
		return (true);
	if (s_flags_2(s))
		return (true);
	if (s_flags_3(s))
		return (true);
	if (s_flags_4(s))
		return (true);
	return (false);
}
