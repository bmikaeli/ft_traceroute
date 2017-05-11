/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ullitoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:47:50 by bmikaeli          #+#    #+#             */
/*   Updated: 2017/04/19 12:27:52 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

static void		s_addchar(char **s, char c)
{
	int		len;
	char	*tmp;

	len = 2;
	if (*s)
		len = ft_strlen(*s) + 1;
	if ((tmp = ft_strnew(len)) == NULL)
		return ;
	if (*s)
	{
		ft_strcpy(tmp, *s);
		tmp[len - 1] = c;
	}
	else
		tmp[0] = c;
	ft_strdel(s);
	*s = tmp;
}

static void		s_strcal(char **s, unsigned long n)
{
	if (n < 10)
		s_addchar(s, '0' + n);
	else
	{
		s_strcal(s, n / 10);
		s_addchar(s, '0' + n % 10);
	}
}

char			*ullitoa(unsigned long n)
{
	char	*str;

	str = NULL;
	s_strcal(&str, n);
	return (str);
}
