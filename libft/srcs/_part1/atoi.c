/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/22 13:41:45 by bmikaeli          #+#    #+#             */
/*   Updated: 2017/04/14 14:28:06 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	s_searchchr(int c)
{
	char	*buf;
	int		i;

	buf = "\n\v\t\r\f ";
	i = 0;
	while (i < 6)
	{
		if (buf[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int			ft_atoi(const char *str)
{
	int		result;
	int		is_neg;

	result = 0;
	is_neg = 1;
	if (str == NULL)
		return (0);
	while (s_searchchr(*str))
		str++;
	while ((*str == '+' || *str == '-') && is_neg == 1)
	{
		if (*str == '-' || *(str + 1) == '+')
		{
			is_neg = -1;
			if (*(str - 1) == '+')
				str--;
		}
		str++;
	}
	while (*str && ft_isdigit(*str))
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (result * is_neg);
}
