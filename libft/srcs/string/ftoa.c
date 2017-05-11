/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 08:37:48 by bmikaeli          #+#    #+#             */
/*   Updated: 2017/04/21 11:57:58 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <math.h>

static void		s_addchar(char **s, char c)
{
	int		len;
	char	*tmp;

	len = 2;
	if (*s)
		len = ft_strlen(*s) + 1;
	if ((tmp = ft_strnew(len)) == NULL)
		return ;
	if (*s)
	{
		ft_strcpy(tmp, *s);
		tmp[len - 1] = c;
	}
	else
		tmp[0] = c;
	ft_strdel(s);
	*s = tmp;
}

static void		s_strcal(char **s, long n)
{
	if (n < 0)
	{
		s_addchar(s, '-');
		n = n * -1;
	}
	if (n < 10)
	{
		s_addchar(s, '0' + n);
	}
	else
	{
		s_strcal(s, n / 10);
		s_addchar(s, '0' + n % 10);
	}
}

static void		s_strcal_p(char **s, long n, long *prec)
{
	if (n < 0)
	{
		s_addchar(s, '-');
		n = n * -1;
	}
	if (n < 10)
	{
		s_addchar(s, '0' + n);
	}
	else
	{
		--(*prec);
		s_strcal_p(s, n / 10, prec);
		s_addchar(s, '0' + n % 10);
	}
}

long int		s_get_pprec(long prec)
{
	long int	pprec;

	if (prec == -1)
		prec = 6;
	pprec = (prec == 0) ? 0 : 1;
	if (prec > 18)
		prec = 18;
	while (prec)
	{
		pprec = pprec * 10;
		--prec;
	}
	return (pprec);
}

char			*ft_ftoa(double n, long prec)
{
	char		*str;
	long		t;
	long int	pprec;

	str = NULL;
	pprec = s_get_pprec(prec);
	s_strcal(&str, n);
	if ((n - (long)(n)) * pprec > 0)
		t = (n - (long)n) * pprec + 1 / (double)(pprec);
	else
		t = (n - (long)n) * pprec + 1 / (double)(pprec);
	if (pprec == 0)
		return (str);
	t = (t < 0) ? -t : t;
	prec = (prec == -1) ? 6 : prec;
	s_addchar(&str, '.');
	--prec;
	s_strcal_p(&str, t, &prec);
	while (prec > 0)
	{
		s_addchar(&str, '0');
		--prec;
	}
	return (str);
}
