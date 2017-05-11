/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/22 14:26:44 by bmikaeli          #+#    #+#             */
/*   Updated: 2017/04/14 14:28:15 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (*s2 == '\0')
		return ((char *)s1);
	len = ft_strlen(s2);
	while (*s1)
	{
		if (!ft_memcmp(s1++, s2, len))
			return ((char *)s1 - 1);
	}
	return (NULL);
}
