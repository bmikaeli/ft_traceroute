/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 16:46:01 by bmikaeli          #+#    #+#             */
/*   Updated: 2017/04/14 14:28:10 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>
#include <unistd.h>

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	long	*ptr1;
	long	*ptr2;
	char	*cptr1;
	char	*cptr2;

	ptr1 = (long *)s1;
	ptr2 = (long *)s2;
	while (n >= sizeof(long))
	{
		*ptr1 = *ptr2;
		++ptr1;
		++ptr2;
		n -= sizeof(long);
	}
	cptr1 = (char *)ptr1;
	cptr2 = (char *)ptr2;
	while (n > 0)
	{
		*cptr1++ = *cptr2++;
		--n;
	}
	return (s1);
}
