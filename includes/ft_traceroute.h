/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ping.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 16:02:00 by bmikaeli          #+#    #+#             */
/*   Updated: 2017/05/09 10:45:46 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TRACEROUTE_H
# define FT_TRACEROUTE_H

# include <libft.h>
# include <signal.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <netdb.h>
# include <libftprintf.h>
# include <arpa/inet.h>
# include <netinet/in.h>
# include <netinet/ip.h>
# include <netinet/ip_icmp.h>
# include <arpa/inet.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <time.h>
# include <math.h>
# include <sys/time.h>

# define BUFSIZE 1024
# define TIME_EXPIRES -3
# define TIME_TRANSIT -2
# define PORT_UNREACH -1
# define ICMP_LEN 64

typedef struct s_traceroute_packet
{
	int max_ttl;
	int pid;
	int sockfd;
	struct sockaddr_in	send;
	struct sockaddr_in	recv;
	struct sockaddr_in last;
	char			*target;
	char			*host;
	int				n_probes;
} t_traceroute_packet;


t_traceroute_packet *sgt_traceroute_packet ();
void		main_loop();
void		time_sub(struct timeval *out, struct timeval *in);
unsigned short	cksum(unsigned short *addr, int len);
void	set_icmp(struct icmp *icmp, int seq);
int	get_icmp(char *buf, int seq, struct timeval *time_recv);
#endif
