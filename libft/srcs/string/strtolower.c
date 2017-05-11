/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/22 14:16:55 by bmikaeli          #+#    #+#             */
/*   Updated: 2017/04/19 11:48:15 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtolower(char *s)
{
	int		i;
	int		len;
	char	*ret;

	len = ft_strlen(s);
	if ((ret = (char *)malloc((len + 1) * sizeof(char))) == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ret[i] = ft_tolower(s[i]);
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
