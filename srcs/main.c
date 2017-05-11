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


static void		set_hints(struct addrinfo *hints)
{
	ft_bzero(hints, sizeof(struct addrinfo));
	hints->ai_family = AF_UNSPEC;
	hints->ai_socktype = 0;
	hints->ai_protocol = 0;
	hints->ai_canonname = NULL;
	hints->ai_addr = NULL;
	hints->ai_next = NULL;
	hints->ai_flags = AI_CANONNAME;
}

char		*get_host(char *target)
{
	struct addrinfo		hints;
	struct addrinfo		*ret;
	char			buf[BUFSIZE];
	int			s;

	set_hints(&hints);
	if ((s = getaddrinfo(target, NULL, &hints, &ret)))
	{
		ft_printf("ft_traceroute: unknown host: %s\n", target);
		exit(-1);
	}
	while (ret)
	{
		if (ret->ai_family == AF_INET)
		{
			return (ft_strdup(inet_ntop(ret->ai_family,
										&((struct sockaddr_in *)ret->ai_addr)->sin_addr, buf, BUFSIZE)));
		}
		ret = ret->ai_next;
	}
	return (NULL);
}


static void ft_usage(int ac, char *av[])
{
	if (ac != 2)
	{
		ft_printf("Usage : %s <hostname>\n", av[0]);
		exit(-1);
	}
	if (getuid())
	{
		ft_printf("Error: Root privileges needed\n");
		exit(-1);
	}
}

static void init_struct()
{
	t_traceroute_packet *p = sgt_traceroute_packet();

	p->pid = getpid();
	p->n_probes = 5;
	p->max_ttl = 500;
}

static void get_target(char *ip)
{
	struct in_addr tmp;
	t_traceroute_packet *p = sgt_traceroute_packet();

	p->target = ft_strdup(ip);
	if (!(inet_pton(AF_INET, p->target, &tmp)))
		p->host = get_host(p->target);
	else
		p->host = p->target;

	inet_pton(AF_INET, p->host, &p->send.sin_addr);
}

int main (int ac, char *av[])
{
	t_traceroute_packet *p = sgt_traceroute_packet();
	ft_usage(ac, av);
	init_struct();
	if ((p->sockfd = socket(PF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0)
	{
		ft_printf("Error: Cannot create socket.\n");
		exit(-1);
	}
	get_target(av[1]);

	printf("traceroute to %s (%s), %d hops max, 60 byte packets\n", p->target, inet_ntoa(p->send.sin_addr), p->max_ttl);
	main_loop();
	return (0);
}