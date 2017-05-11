/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   report_results.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 15:05:51 by bmikaeli          #+#    #+#             */
/*   Updated: 2017/05/09 10:01:23 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_traceroute.h>

static int				pars(int seq, struct timeval *time_recv)
{
	t_traceroute_packet *p = sgt_traceroute_packet();
	socklen_t			len;
	char				recv_buf[BUFSIZE];
	struct timeval		wait;
	fd_set				fds;

	wait.tv_sec = 0;
	wait.tv_usec = 1700000;
	while (1)
	{
		len = sizeof(p->recv);
		FD_ZERO(&fds);
		FD_SET(p->sockfd, &fds);
		if (select(p->sockfd + 1, &fds, NULL, NULL, &wait) > 0)
			recvfrom(p->sockfd, recv_buf, sizeof(recv_buf), 0, (struct sockaddr *)&p->recv, &len);
		else if (!FD_ISSET(p->sockfd, &fds))
			return (TIME_EXPIRES);
		else
		{
			ft_printf("Error: recvfrom failed.\n");
			exit(-1);
		}
		return (get_icmp(recv_buf, seq, time_recv));
	}
}



static void				loop_probe(int seq, int *done)
{
	t_traceroute_packet *p = sgt_traceroute_packet();

	struct icmp			*icmp;
	char				send_buf[BUFSIZE];
	char				tmp[BUFSIZE];
	struct timeval		*time_send;
	struct timeval		time_recv;
	int					ret;
	double				rtt;

	icmp = (struct icmp *)send_buf;
	set_icmp(icmp, seq);
	icmp->icmp_seq = ++seq;
	time_send = (struct timeval *)icmp->icmp_data;
	gettimeofday(time_send, NULL);
	icmp->icmp_cksum = cksum((unsigned short *)icmp, ICMP_LEN);
	if (sendto(p->sockfd, send_buf, ICMP_LEN, 0, (struct sockaddr *)&p->send, sizeof(p->send)) < 0)
	{
		ft_printf("Error: sendto failed\n");
		exit(-1);
	}
	if ((ret = pars(seq, &time_recv)) == TIME_EXPIRES)
		printf(" *");
	else
	{
		if (ft_memcmp(&p->recv.sin_addr, &p->last.sin_addr, sizeof(p->recv.sin_addr)))
		{
			if (!(getnameinfo((struct sockaddr *)&(p->recv), sizeof(p->recv), tmp, BUFSIZE, NULL, 0, 0)))
				printf(" %s (%s)", tmp, inet_ntoa(p->recv.sin_addr));
			else
				printf(" %s", inet_ntoa(p->recv.sin_addr));
			ft_memcpy(&p->last.sin_addr, &p->recv.sin_addr, sizeof(p->last.sin_addr));
		}
		time_sub(&time_recv, time_send);
		rtt = time_recv.tv_sec * 1000.0 + time_recv.tv_usec / 1000.0;
		printf("  %.3f ms", rtt);
		if (ret == -1)
			++*done;
	}
}

void					main_loop()
{
	t_traceroute_packet *p = sgt_traceroute_packet();

	int					seq;
	int					done;
	int					ttl;
	int					probe;

	seq = 0;
	done = 0;
	ttl = 1;
	while (ttl <= p->max_ttl && !done)
	{
		probe = 0;
		if (setsockopt(p->sockfd, SOL_IP, IP_TTL, &ttl, sizeof(ttl)) == -1)
		{
			ft_printf("Error: setsockopt failed\n");
			exit(-1);
		}
		ft_bzero(&p->last, sizeof(p->last));
		ft_printf("%2d ", ttl);
		while (probe < p->n_probes)
		{
			loop_probe(seq, &done);
			probe++;
		}
		printf("\n");
		ttl++;
	}
}