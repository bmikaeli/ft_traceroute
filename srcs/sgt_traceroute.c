/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sgt_ping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 13:41:59 by bmikaeli          #+#    #+#             */
/*   Updated: 2017/05/06 14:16:11 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_traceroute.h>

t_traceroute_packet *sgt_traceroute_packet ()
{
	static t_traceroute_packet *t = NULL;

	if (t == NULL)
		t = (t_traceroute_packet *) malloc(sizeof(t_traceroute_packet) * 1);
	return (t);
}
