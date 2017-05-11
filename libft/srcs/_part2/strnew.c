/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnew.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/22 14:24:03 by bmikaeli          #+#    #+#             */
/*   Updated: 2017/04/14 14:28:25 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	if (size == 0)
		return (NULL);
	if ((str = (char *)malloc((size + 1) * sizeof(char))) == NULL)
		return (NULL);
	ft_bzero(str, size + 1);
	return (str);
}
