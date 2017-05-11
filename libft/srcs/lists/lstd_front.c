/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstd_front.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/14 05:29:15 by bmikaeli          #+#    #+#             */
/*   Updated: 2017/04/14 14:28:29 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_listd		*ft_lstd_front(t_listd *lstd)
{
	if (lstd && lstd->prev)
		return (ft_lstd_front(lstd->prev));
	return (lstd);
}
