/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/22 13:55:36 by bmikaeli          #+#    #+#             */
/*   Updated: 2017/04/14 14:28:09 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <unistd.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char		*cpy1;
	const unsigned char		*cpy2;
	size_t					i;

	cpy1 = s1;
	cpy2 = s2;
	i = 0;
	while (i < n)
	{
		if (*cpy1 != *cpy2)
		{
			return (*cpy1 - *cpy2);
		}
		else
		{
			cpy1++;
			cpy2++;
		}
		i++;
	}
	return (0);
}
