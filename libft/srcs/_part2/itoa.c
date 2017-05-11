/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/22 13:47:59 by bmikaeli          #+#    #+#             */
/*   Updated: 2017/04/14 14:28:17 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>
#include <unistd.h>

static void		s_strcal(char **s, long long int n, char *base, size_t len)
{
	if (n < 0)
	{
		(**s) = '-';
		++(*s);
		(**s) = '\0';
		n = n * -1;
	}
	if (n < (long long int)len)
	{
		(**s) = base[n];
		++(*s);
		(**s) = '\0';
	}
	else
	{
		s_strcal(s, n / len, base, len);
		(**s) = base[n % len];
		++(*s);
		(**s) = '\0';
	}
}

char			*ft_itoa(int n)
{
	char	tmp[128];
	char	*str;
	size_t	len;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	str = tmp;
	s_strcal(&str, n, "0123456789", 10);
	len = str - tmp + 1;
	if ((str = (char *)malloc((len) * sizeof(char))) == NULL)
		return (NULL);
	ft_memcpy(str, tmp, len);
	return (str);
}
