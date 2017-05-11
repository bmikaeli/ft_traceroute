/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 11:15:32 by bmikaeli          #+#    #+#             */
/*   Updated: 2017/04/21 13:04:00 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <libft.h>
# include <limits.h>
# include <stdarg.h>
# include <wchar.h>
# include <inttypes.h>
# include <stdlib.h>

# define IS_BIG_LONG	LONG_MAX != LONG_LONG_MAX
# define MIN(a, b)		(((a) < (b)) ? (a) : (b))
# define MAX(a, b)		(((a) > (b)) ? (a) : (b))

typedef enum				e_printf_conversion
{
	percent,
	s,
	big_s,
	p,
	d,
	big_d,
	i,
	o,
	big_o,
	u,
	big_u,
	x,
	big_x,
	c,
	big_c,
	b,
	big_b,
	f,
	big_f,
	conversion_len
}							t_printf_conversion;

typedef union				u_number
{
	unsigned long long int	longlong;
	unsigned long int		word;
	double					longdouble;
}							t_number;

typedef struct				s_printf_flag
{
	t_bool					is_negative;
	t_number				number;
	int						base;
	t_bool					alt;
	t_bool					space;
	t_bool					left;
	t_bool					showsign;
	t_bool					group;
	t_bool					is_long_double;
	t_bool					is_short;
	t_bool					is_long;
	t_bool					is_char;
	int						width;
	int						prec;
	char					pad;
	char					spec;
}							t_printf_flag;

typedef void				(*t_ptr_flag_func)();

typedef struct				s_printf
{
	char					*buffer;
	int						len;
	va_list					args;
	t_printf_flag			flags;
	char					*work_buffer;
	t_ptr_flag_func			ptr_funcs[conversion_len];
	t_listd					*bszero;
	t_listd					*characters;
}							t_printf;

int							ft_printf(const char *format, ...);
void						add_char(unsigned char c);
void						add_string(char *s);
void						add_wchar(wchar_t c);
char						*concat2(char *s1, int len1, char *s2, int len2);
char						*concat(char *s1, int *len1, char *s2, int len2);
void						fill_character(char c);
t_bool						flags(char **s);
void						form_interger(void);
void						form_percent(void);
char						arg_get_char(void);
unsigned char				arg_get_uchar(void);
wchar_t						arg_get_wchar(void);
double						arg_get_double(void);
long double					arg_get_longdouble(void);
int							arg_get_int(void);
unsigned int				arg_get_uint(void);
unsigned long				arg_get_ulong(void);
long int					arg_get_long_int(void);
unsigned long int			arg_get_ulong_int(void);
long long int				arg_get_long_long_int(void);
unsigned long long int		arg_get_ulong_long_int(void);
char						*arg_get_string(void);
wchar_t						*arg_get_wstring(void);
void						*arg_get_void(void);
t_bool						modifiers(char **s);
int							ft_max(int a, int b);
void						number(void);
void						number_type(void);
void						number_left(void);
t_printf					*sgt_printf(void);
void						ini_printf(void);
void						ini_flags(void);
size_t						strwlen_print(const wchar_t *s);
void						to_string(char *s);
void						to_char(char c);
void						to_wchar(wchar_t c);
char						*ullitoa(unsigned long n);
char						*wstr_to_str(wchar_t *s);
void						conversion_x(void);
void						conversion_i(void);
void						conversion_u(void);
void						conversion_big_u(void);
void						conversion_big_f(void);
void						conversion_f(void);
void						conversion_big_b(void);
void						conversion_b(void);
void						conversion_big_d(void);
void						conversion_big_o(void);
void						conversion_big_x(void);
void						conversion_big_c(void);
void						conversion_c(void);
void						conversion_o(void);
void						conversion_p(void);
void						conversion_big_s(void);
void						conversion_s(void);
#endif
