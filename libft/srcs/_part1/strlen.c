/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/22 14:18:50 by bmikaeli          #+#    #+#             */
/*   Updated: 2017/04/14 14:28:13 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	ft_strlen(const char *s)
{
	char	*tmp;

	if (!s)
		return (0);
	tmp = (char *)s;
	while (*tmp)
		++tmp;
	return (tmp - s);
}
