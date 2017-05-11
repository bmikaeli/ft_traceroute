/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstd_push_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 19:09:12 by bmikaeli          #+#    #+#             */
/*   Updated: 2017/04/14 14:28:38 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstd_push_back(t_listd **alst, void *new)
{
	t_listd		*last;
	t_listd		*tmp;

	if (!alst || !*alst)
	{
		ft_lstd_new(alst, new);
		return ;
	}
	if ((tmp = (t_listd *)malloc(sizeof(t_listd))) != NULL)
	{
		last = ft_lstd_back(*alst);
		tmp->data = new;
		tmp->prev = last;
		tmp->next = NULL;
		last->next = tmp;
	}
}
