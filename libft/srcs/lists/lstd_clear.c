/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstd_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 15:52:18 by bmikaeli          #+#    #+#             */
/*   Updated: 2017/04/14 14:28:27 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstd_clear(t_listd **alst, void (*del)(void*))
{
	t_listd		*tmp;

	if (!alst || !*alst)
		return ;
	while (*alst)
	{
		if (del)
			del((*alst)->data);
		tmp = *alst;
		*alst = (*alst)->next;
		free(tmp);
	}
}
