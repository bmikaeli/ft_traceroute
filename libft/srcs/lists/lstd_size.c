/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstd_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/14 05:24:24 by bmikaeli          #+#    #+#             */
/*   Updated: 2017/04/14 14:27:32 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstd_size(t_listd *lstd)
{
	size_t		count;
	t_listd		*front;

	count = 0;
	front = ft_lstd_front(lstd);
	while (front)
	{
		++count;
		front = front->next;
	}
	return (count);
}
