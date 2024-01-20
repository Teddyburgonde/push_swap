# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 18:28:34 by tebandam          #+#    #+#              #
#    Updated: 2024/01/19 11:26:26 by tebandam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

SRCS=ft_print_hexa_lowercase.c ft_print_hexa_uppercase.c ft_printf.c \
     ft_putchar.c ft_putstr.c ft_putnbr.c print_ptr_hexa.c

OBJS=$(SRCS:.c=.o)

RM=rm -f

CC= clang
ARRC=ar -rc
CFLAGS=-Wall -Wextra -Werror -g

all: $(NAME)

$(NAME) : $(OBJS)
	@$(ARRC) $(NAME) $(OBJS)
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
clean: 
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
