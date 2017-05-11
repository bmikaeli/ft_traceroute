/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 11:16:31 by bmikaeli          #+#    #+#             */
/*   Updated: 2017/04/19 12:25:11 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

void	add_char(unsigned char c)
{
	int		len;
	char	*tmp;

	len = 2;
	if (sgt_printf()->buffer != NULL)
		len = sgt_printf()->len + 1;
	if ((tmp = ft_strnew(len)) == NULL)
		return ;
	if (sgt_printf()->buffer)
	{
		ft_memcpy(tmp, sgt_printf()->buffer, sgt_printf()->len);
		tmp[len - 1] = c;
		++sgt_printf()->len;
	}
	else
	{
		tmp[0] = c;
		++sgt_printf()->len;
	}
	ft_strdel(&sgt_printf()->buffer);
	sgt_printf()->buffer = tmp;
}
