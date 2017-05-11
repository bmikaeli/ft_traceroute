/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstd_get_last.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 15:21:37 by bmikaeli          #+#    #+#             */
/*   Updated: 2017/04/14 14:29:09 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_listd		*ft_lstd_get_last(t_listd *alst)
{
	if (alst && alst->next)
		return (ft_lstd_get_last(alst->next));
	return (alst);
}
