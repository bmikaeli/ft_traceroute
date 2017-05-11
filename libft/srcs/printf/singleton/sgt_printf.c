/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sgt_printf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/18 12:01:56 by bmikaeli          #+#    #+#             */
/*   Updated: 2017/04/19 12:55:50 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

static void			s_ini_ptr_functions(t_printf **ptr)
{
	(*ptr)->ptr_funcs[percent] = &form_percent;
	(*ptr)->ptr_funcs[s] = &conversion_s;
	(*ptr)->ptr_funcs[big_s] = &conversion_big_s;
	(*ptr)->ptr_funcs[p] = &conversion_p;
	(*ptr)->ptr_funcs[d] = &conversion_i;
	(*ptr)->ptr_funcs[big_d] = &conversion_big_d;
	(*ptr)->ptr_funcs[i] = &conversion_i;
	(*ptr)->ptr_funcs[o] = &conversion_o;
	(*ptr)->ptr_funcs[big_o] = &conversion_big_o;
	(*ptr)->ptr_funcs[u] = &conversion_u;
	(*ptr)->ptr_funcs[big_u] = &conversion_big_u;
	(*ptr)->ptr_funcs[x] = &conversion_x;
	(*ptr)->ptr_funcs[big_x] = &conversion_big_x;
	(*ptr)->ptr_funcs[c] = &conversion_c;
	(*ptr)->ptr_funcs[big_c] = &conversion_big_c;
	(*ptr)->ptr_funcs[b] = &conversion_b;
	(*ptr)->ptr_funcs[big_b] = &conversion_big_b;
	(*ptr)->ptr_funcs[f] = &conversion_f;
	(*ptr)->ptr_funcs[big_f] = &conversion_big_f;
}

static t_printf		*s_ini_sgt_printf(void)
{
	t_printf	*alloc;

	if ((alloc = (t_printf *)malloc(sizeof(t_printf))) == NULL)
		exit(-1);
	alloc->buffer = NULL;
	alloc->len = 0;
	alloc->bszero = NULL;
	alloc->characters = NULL;
	s_ini_ptr_functions(&alloc);
	return (alloc);
}

t_printf			*sgt_printf(void)
{
	static t_printf		*s = NULL;

	if (s == NULL)
		s = s_ini_sgt_printf();
	return (s);
}

void				ini_printf(void)
{
	sgt_printf()->buffer = NULL;
	sgt_printf()->len = 0;
	sgt_printf()->bszero = NULL;
	sgt_printf()->characters = NULL;
}

void				ini_flags(void)
{
	sgt_printf()->work_buffer = NULL;
	sgt_printf()->flags.is_negative = false;
	sgt_printf()->flags.number.longlong = 0;
	sgt_printf()->flags.base = 10;
	sgt_printf()->flags.alt = false;
	sgt_printf()->flags.space = false;
	sgt_printf()->flags.left = false;
	sgt_printf()->flags.showsign = false;
	sgt_printf()->flags.group = false;
	sgt_printf()->flags.is_long_double = false;
	sgt_printf()->flags.is_short = false;
	sgt_printf()->flags.is_long = false;
	sgt_printf()->flags.is_char = false;
	sgt_printf()->flags.width = 0;
	sgt_printf()->flags.prec = -1;
	sgt_printf()->flags.pad = ' ';
	sgt_printf()->flags.spec = '\0';
}
