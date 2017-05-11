/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstd_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/14 05:31:34 by bmikaeli          #+#    #+#             */
/*   Updated: 2017/04/14 14:28:27 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_listd		*ft_lstd_back(t_listd *lstd)
{
	if (lstd && lstd->next)
		return (ft_lstd_back(lstd->next));
	return (lstd);
}
