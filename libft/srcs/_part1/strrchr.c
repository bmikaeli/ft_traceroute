/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/22 14:25:28 by bmikaeli          #+#    #+#             */
/*   Updated: 2017/04/14 14:28:15 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*chr;

	chr = NULL;
	if (*s == (char)c)
		chr = (char *)s;
	while (*s)
	{
		if (*s == c)
			chr = (char *)s;
		s++;
	}
	if (c == '\0')
		chr = (char *)s;
	return (chr);
}
