/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/22 13:57:57 by bmikaeli          #+#    #+#             */
/*   Updated: 2017/04/14 14:28:10 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memset(void *b, int c, size_t len)
{
	char	*cptr;

	cptr = (char *)b;
	while (len > 0)
	{
		*cptr = (char)c;
		++cptr;
		--len;
		if (len > 0)
		{
			*cptr = c;
			++cptr;
			--len;
		}
	}
	return (b);
}
