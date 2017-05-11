/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putendl_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/22 14:01:28 by bmikaeli          #+#    #+#             */
/*   Updated: 2017/04/14 14:28:19 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <unistd.h>

void	ft_putendl_fd(char const *s, int fd)
{
	char	*tmp;
	int		len;

	if (!s)
		write(fd, "\n", 1);
	len = ft_strlen(s);
	tmp = ft_strnew(len + 1);
	tmp = ft_memcpy(tmp, s, len + 1);
	tmp[len] = '\n';
	write(fd, tmp, len + 1);
	ft_strdel(&tmp);
}
