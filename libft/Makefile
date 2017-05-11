# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/03 11:00:17 by bmikaeli          #+#    #+#              #
#    Updated: 2017/04/21 13:19:39 by bmikaeli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

NAMEBASE    =   $(shell basename $(NAME) .a)

LENGTHNAME	=	`printf "%s" $(NAMEBASE) | wc -c`

MAX_COLS	=	$$(echo "$$(tput cols)-24-$(LENGTHNAME)"|bc)

CC			=	clang

FLAGS		=	-Wall -Wextra -Werror -O3

SRCDIR		=	srcs/

OBJDIR		=	objs/

INCDIR		=	includes/

SRCBASE		=	_part1/atoi.c												\
				_part1/bzero.c												\
				_part1/isalnum.c											\
				_part1/isalpha.c											\
				_part1/isascii.c											\
				_part1/isdigit.c											\
				_part1/isprint.c											\
				_part1/memccpy.c											\
				_part1/memchr.c												\
				_part1/memcmp.c												\
				_part1/memcpy.c												\
				_part1/memmove.c											\
				_part1/memset.c												\
				_part1/strcat.c												\
				_part1/strchr.c												\
				_part1/strcmp.c												\
				_part1/strcpy.c												\
				_part1/strdup.c												\
				_part1/strlcat.c											\
				_part1/strlen.c												\
				_part1/strncat.c											\
				_part1/strncmp.c											\
				_part1/strncpy.c											\
				_part1/strnstr.c											\
				_part1/strrchr.c											\
				_part1/strstr.c												\
				_part1/tolower.c											\
				_part1/toupper.c											\
				_part2/itoa.c												\
				_part2/memalloc.c											\
				_part2/memdel.c												\
				_part2/putchar.c											\
				_part2/putchar_fd.c											\
				_part2/putendl.c											\
				_part2/putendl_fd.c											\
				_part2/putnbr.c												\
				_part2/putnbr_fd.c											\
				_part2/putstr.c												\
				_part2/putstr_fd.c											\
				_part2/strclr.c												\
				_part2/strdel.c												\
				_part2/strequ.c												\
				_part2/striter.c											\
				_part2/striteri.c											\
				_part2/strjoin.c											\
				_part2/strmap.c												\
				_part2/strmapi.c											\
				_part2/strnequ.c											\
				_part2/strnew.c												\
				_part2/strsplit.c											\
				_part2/strsub.c												\
				_part2/strtrim.c											\
				lists/lstd_back.c											\
				lists/lstd_clear.c											\
				lists/lstd_del.c											\
				lists/lstd_do.c												\
				lists/lstd_front.c											\
				lists/lstd_get_last.c										\
				lists/lstd_map.c											\
				lists/lstd_new.c											\
				lists/lstd_pop_back.c										\
				lists/lstd_pop_front.c										\
				lists/lstd_push_after.c										\
				lists/lstd_push_back.c										\
				lists/lstd_push_before.c									\
				lists/lstd_push_cond.c										\
				lists/lstd_push_front.c										\
				lists/lstd_rmap.c											\
				lists/lstd_size.c											\
				get_next_line.c												\
				printf/add/add_char.c										\
				printf/add/add_string.c										\
				printf/add/add_wchar.c										\
				printf/add/fill_character.c									\
				printf/arg_get/get_char.c									\
				printf/arg_get/get_double.c									\
				printf/arg_get/get_int.c									\
				printf/arg_get/get_long.c									\
				printf/arg_get/get_string.c									\
				printf/arg_get/get_void.c									\
				printf/conversion/b.c										\
				printf/conversion/big_d.c									\
				printf/conversion/c.c										\
				printf/conversion/f.c										\
				printf/conversion/i.c										\
				printf/conversion/o.c										\
				printf/conversion/p.c										\
				printf/conversion/s.c										\
				printf/conversion/to_string.c								\
				printf/conversion/u.c										\
				printf/conversion/x.c										\
				printf/flags.c												\
				printf/ft_printf.c											\
				printf/label/form_interger.c								\
				printf/label/form_percent.c									\
				printf/label/number.c										\
				printf/label/number2.c										\
				printf/label/number_left.c									\
				printf/modifiers.c											\
				printf/singleton/sgt_printf.c								\
				printf/strwlen_print.c										\
				printf/ullitoa.c											\
				printf/wstr_to_str.c										\
				string/atol.c												\
				string/basetoa.c											\
				string/ftoa.c												\
				string/isnumber.c											\
				string/ltoa.c												\
				string/strsplit_tolist.c									\
				string/strtolower.c											\
				string/strtoupper.c											\
				string/ubasetoa.c									

SRCS		=	$(addprefix $(SRCDIR), $(SRCBASE))

OBJS		=	$(addprefix $(OBJDIR), $(SRCBASE:.c=.o))


all: $(NAME)

$(NAME):	$(OBJDIR) $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)
	mkdir -p $(dir $(OBJS))

$(OBJDIR)%.o : $(SRCDIR)%.c | $(OBJDIR)
	$(CC) $(FLAGS) -MMD -c $< -o $@	-I $(INCDIR)
	

clean:
	rm -rf $(OBJDIR) 

fclean:		clean
	rm -rf $(NAME)

re:			fclean all

.PHONY:		fclean clean re

-include $(OBJS:.o=.d)
