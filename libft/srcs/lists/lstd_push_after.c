/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstd_push_after.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/21 16:24:02 by bmikaeli          #+#    #+#             */
/*   Updated: 2017/04/14 14:28:38 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstd_push_after(t_listd **alst, void *new)
{
	t_listd		*after;
	t_listd		*tmp;

	if (!alst || !*alst)
	{
		ft_lstd_new(alst, new);
		return ;
	}
	if ((tmp = (t_listd *)malloc(sizeof(t_listd))) != NULL)
	{
		after = (*alst)->next;
		tmp->data = new;
		tmp->prev = *alst;
		tmp->next = after;
		(*alst)->next = tmp;
	}
}
