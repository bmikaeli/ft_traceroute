/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/17 12:29:09 by bmikaeli          #+#    #+#             */
/*   Updated: 2017/04/19 12:28:05 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

t_bool			check_conversion(char **s)
{
	int		i;
	char	*flags;

	i = 0;
	flags = ft_strdup("%sSpdDioOuUxXcCbBfF");
	while (flags && flags[i])
	{
		if (**s == flags[i])
			break ;
		i++;
	}
	if (flags[i] == '\0')
	{
		ft_strdel(&flags);
		return (false);
	}
	sgt_printf()->ptr_funcs[i]();
	ft_strdel(&flags);
	return (true);
}

void			check_action(char **s)
{
	char	*tmp;
	char	sc[2];

	tmp = *s;
	++(*s);
	while ((flags(s) || modifiers(s)))
		++(*s);
	if (**s)
	{
		if (check_conversion(s) == false)
		{
			sc[0] = **s;
			sc[1] = '\0';
			sgt_printf()->flags.prec = -1;
			to_string(ft_strdup(sc));
		}
	}
	else
		--(*s);
}

static void		s_printf(char *s)
{
	char	*str;

	str = NULL;
	while (*s)
	{
		ini_flags();
		if (*s == '%')
			check_action(&s);
		else
			add_char(*s);
		++s;
	}
}

int				ft_printf(const char *restrict format, ...)
{
	ini_printf();
	va_start(sgt_printf()->args, format);
	s_printf((char *)format);
	va_end(sgt_printf()->args);
	write(1, sgt_printf()->buffer, sgt_printf()->len);
	ft_strdel(&sgt_printf()->buffer);
	return (sgt_printf()->len);
}
