/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstd_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/22 14:27:15 by bmikaeli          #+#    #+#             */
/*   Updated: 2017/04/14 14:28:36 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstd_map(t_listd **alst, void (*map)())
{
	t_listd		*scan;

	if (!alst || !*alst)
		return ;
	scan = ft_lstd_front(*alst);
	while (scan)
	{
		map(scan->data);
		scan = scan->next;
	}
}
