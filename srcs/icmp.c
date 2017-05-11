/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 16:01:58 by bmikaeli          #+#    #+#             */
/*   Updated: 2017/05/09 10:45:28 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_traceroute.h>

void					set_icmp(struct icmp *icmp, int seq)
{
	t_traceroute_packet *p = sgt_traceroute_packet();

	icmp->icmp_type = ICMP_ECHO;
	icmp->icmp_code = 0;
	icmp->icmp_id = p->pid;
	icmp->icmp_seq = ++seq;
	icmp->icmp_cksum = 0;
}

int						get_icmp(char *buf, int seq, struct timeval *time_recv)
{
	t_traceroute_packet *p = sgt_traceroute_packet();

	struct ip			*ip;
	struct ip			*hdr_ip;
	struct icmp			*icmp;
	struct icmp			*hdr_icmp;
	int					hdr_len1;
	int					hdr_len2;

	gettimeofday(time_recv, NULL);
	ip = (struct ip *)buf;
	hdr_len1 = ip->ip_hl * 4;
	icmp = (struct icmp *)(buf + hdr_len1);
	if (icmp->icmp_type == ICMP_TIMXCEED && icmp->icmp_code == ICMP_TIMXCEED_INTRANS)
	{
		hdr_ip = (struct ip *)(buf + hdr_len1 + 8);
		hdr_len2 = hdr_ip->ip_hl * 4;
		hdr_icmp = (struct icmp *)(buf + hdr_len1 + 8 + hdr_len2);
		if (hdr_icmp->icmp_id == p->pid && hdr_icmp->icmp_seq == seq)
			return (TIME_TRANSIT);
	}
	if (icmp->icmp_type == ICMP_ECHOREPLY && icmp->icmp_id == p->pid && icmp->icmp_seq == seq)
		return (PORT_UNREACH);
	return (0);
}