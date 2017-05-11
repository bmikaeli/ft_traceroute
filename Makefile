# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/07 09:22:24 by bmikaeli          #+#    #+#              #
#    Updated: 2017/05/06 14:12:16 by bmikaeli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	./ft_traceroute
CC		= 	clang
FLAGS		=	-Wall -Wextra #-Werror

SRCDIR		=	srcs/
OBJDIR		=	objs/
INCDIR		=	includes/
LIBFT_DIR	=	./libft/
LIBFT_LIB	=	$(LIBFT_DIR)libft.a

SRCBASE		=	main.c sgt_traceroute.c main_loop.c utils.c icmp.c

SRCS		=	$(addprefix $(SRCDIR), $(SRCBASE))
INCS		=	$(addprefix $(INCDIR), $(INCBASE))
OBJS		=	$(addprefix $(OBJDIR), $(SRCBASE:.c=.o))

all:		$(NAME)

$(NAME):	$(OBJDIR) $(OBJS)
	make -C $(LIBFT_DIR)
	$(CC) -lm $(FLAGS) -o $(NAME) $(OBJS) $(LIBFT_LIB)

$(OBJDIR):
	mkdir -p $(OBJDIR)
	mkdir -p $(dir $(OBJS))

$(OBJDIR)%.o : $(SRCDIR)%.c | $(OBJDIR)
	$(CC) $(FLAGS) -MMD -c $< -o $@											\
		-I $(LIBFT_DIR)$(INCDIR)											\
		-I $(INCDIR)


clean:
	make -C $(LIBFT_DIR) clean
	rm -rf $(OBJDIR)

fclean:		clean
	make -C $(LIBFT_DIR) fclean
	rm -rf $(NAME)

re:			fclean all

relib:		fclean fcleanlib all

.PHONY:		fclean fcleanlib clean re relib

-include $(OBJS:.o=.d)
