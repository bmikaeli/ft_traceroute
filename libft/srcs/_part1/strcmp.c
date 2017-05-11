/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/22 14:07:11 by bmikaeli          #+#    #+#             */
/*   Updated: 2017/04/14 14:28:12 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	if ((*s2 != '\0') && (*s1 != '\0') && (*s1 == *s2))
		return (ft_strcmp(++s1, ++s2));
	else
		return ((unsigned char)*s1 - (unsigned char)*s2);
}
