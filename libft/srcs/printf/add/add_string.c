/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/19 23:18:57 by bmikaeli          #+#    #+#             */
/*   Updated: 2017/04/19 12:25:17 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

static char		*s_strjoin(char *s1, char *s2)
{
	char	*tmp;

	if ((tmp = ft_strnew(sgt_printf()->len + ft_strlen(s2))) == NULL)
		return (NULL);
	ft_memcpy(tmp, s1, sgt_printf()->len);
	ft_memcpy(tmp + sgt_printf()->len, s2, ft_strlen(s2));
	return (tmp);
}

void			add_string(char *s)
{
	char	*tmp;
	char	*str;

	str = sgt_printf()->buffer;
	tmp = NULL;
	if (str != NULL)
	{
		tmp = s_strjoin(str, s);
	}
	else if (s != NULL)
		tmp = ft_strdup(s);
	if (tmp != NULL)
	{
		ft_strdel(&sgt_printf()->buffer);
		sgt_printf()->buffer = tmp;
		sgt_printf()->len += ft_strlen(s);
	}
	ft_strdel(&s);
}
