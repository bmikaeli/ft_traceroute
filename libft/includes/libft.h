/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 05:52:47 by bmikaeli          #+#    #+#             */
/*   Updated: 2017/04/19 11:48:07 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define BUFF_SIZE		1024

# ifndef INT_MIN
#  define INT_MIN		(-2147483647-1)
# endif
# ifndef INT_MAX
#  define INT_MAX		2147483647
# endif
# ifndef LONG_MIN
#  define LONG_MIN		(-0x7fffffffffffffffL-1)
# endif
# ifndef LONG_MAX
#  define LONG_MAX		0x7fffffffffffffffL
# endif
# ifndef LLONG_MIN
#  define LLONG_MIN		(-0x7fffffffffffffffLL-1)
# endif
# ifndef LLONG_MAX
#  define LLONG_MAX		0x7fffffffffffffffLL
# endif
# ifndef NULL
#  define NULL			0
# endif

# include <unistd.h>

/*
** PART 1
*/
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *s1, const void *s2, size_t n);
void				*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void				*ft_memmove(void *s1, const void *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *s1, const char *s2);
char				*ft_strncpy(char *s1, const char *s2, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

/*
** PART 2
*/
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
int					ft_putchar(int c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
int					ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

/*
** STRING
*/
int					ft_isnumber(char *s);
long				ft_atol(const char *s);
char				*ft_strtolower(char *s);
char				*ft_strtoupper(char *s);
char				*ft_ltoa(long n);
char				*ft_basetoa(long long int n, char *base);
char				*ft_ubasetoa(unsigned long int n, char *base);
char				*ft_ftoa(double n, long prec);

/*
** BONUS
*/
typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
** BOOL
*/
typedef enum		e_bool
{
	false,
	true
}					t_bool;

/*
** GET_NEXT_LINE
*/
int					ft_get_next_line(int const fd, char **line);

/*
** LIST
*/
typedef struct		s_listd
{
	void			*data;
	struct s_listd	*prev;
	struct s_listd	*next;
}					t_listd;

size_t				ft_lstd_size(t_listd *lstd);
t_listd				*ft_lstd_front(t_listd *lstd);
t_listd				*ft_lstd_back(t_listd *lstd);
void				ft_lstd_new(t_listd **alst, void *new);
void				ft_lstd_push_front(t_listd **alst, void *new);
void				ft_lstd_push_back(t_listd **alst, void *new);
void				ft_lstd_pop_front(t_listd **alst, void (*del)());
void				ft_lstd_pop_back(t_listd **alst, void (*del)());
void				ft_lstd_push_after(t_listd **alst, void *new);
void				ft_lstd_push_before(t_listd **alst, void *new);
void				ft_lstd_push_cond(t_listd **alst, void *new,
		int (*cond)());
void				ft_lstd_del(t_listd **alst, void (*del)());
void				ft_lstd_clear(t_listd **alst, void (*del)());
void				ft_lstd_map(t_listd **alst, void (*map)());
void				ft_lstd_rmap(t_listd **alst, void (*map)());
void				ft_lstd_do(t_listd **alst, int (*cmp)(),
		void (*action)(), int type);

#endif
