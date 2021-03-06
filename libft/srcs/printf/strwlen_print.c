/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strwlen_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 21:45:20 by bmikaeli          #+#    #+#             */
/*   Updated: 2017/04/21 11:59:40 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

size_t	strwlen_print(const wchar_t *s)
{
	size_t	i;
	size_t	len;

	if (!s)
		return (0);
	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] <= 0x7F)
			len += 1;
		else if (s[i] <= 0x7FF)
			len += 2;
		else if (s[i] <= 0xFFFF)
			len += 3;
		else if (s[i] <= 0x10FFFF)
			len += 4;
		++i;
	}
	return (len);
}
