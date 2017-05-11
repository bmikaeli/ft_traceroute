/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putchar_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/22 14:00:04 by bmikaeli          #+#    #+#             */
/*   Updated: 2017/04/14 14:28:18 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}
