/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 05:05:40 by bmikaeli          #+#    #+#             */
/*   Updated: 2017/04/21 12:09:31 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

int				ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

char			*concat2(char *s1, int len1, char *s2, int len2)
{
	char		*tmp;

	if ((tmp = ft_strnew(len1 + len2)) == NULL)
		return (NULL);
	ft_memcpy(tmp, s1, len1);
	ft_memcpy(tmp + len1, s2, len2);
	ft_strdel(&s1);
	return (tmp);
}

char			*concat(char *s1, int *len1, char *s2, int len2)
{
	char		*tmp;

	if ((tmp = ft_strnew(*len1 + len2)) == NULL)
		return (NULL);
	ft_memcpy(tmp, s1, *len1);
	ft_memcpy(tmp + *len1, s2, len2);
	ft_strdel(&s1);
	*len1 += len2;
	return (tmp);
}

void			number_type(void)
{
	if (sgt_printf()->flags.spec == 'f')
		sgt_printf()->work_buffer = ft_ftoa(
				sgt_printf()->flags.number.longdouble,
				sgt_printf()->flags.prec);
	else if (sgt_printf()->flags.spec == 'b')
		sgt_printf()->work_buffer = ft_ubasetoa(
				sgt_printf()->flags.number.longlong, "01");
	else if (sgt_printf()->flags.spec == 'x')
		sgt_printf()->work_buffer = ft_ubasetoa(
				sgt_printf()->flags.number.longlong, "0123456789abcdef");
	else if (sgt_printf()->flags.spec == 'X')
		sgt_printf()->work_buffer = ft_ubasetoa(
				sgt_printf()->flags.number.longlong, "0123456789ABCDEF");
	else if (sgt_printf()->flags.base == 8)
		sgt_printf()->work_buffer = ft_ubasetoa(
				sgt_printf()->flags.number.longlong, "01234567");
	else
		sgt_printf()->work_buffer = ft_ubasetoa(
				sgt_printf()->flags.number.longlong, "0123456789");
}
