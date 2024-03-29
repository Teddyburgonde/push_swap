NAME = push_swap

SRCS = ft_printf/ft_printf.c \
	ft_free.c \
	ft_swap_stack.c \
	ft_push.c \
	ft_rotate.c \
	ft_reverse_rotate.c \
	ft_atoi_modif.c \
	ft_normalisation.c \
	ft_sort.c \
	ft_butterfly.c \
	ft_small_sort.c \
	ft_parsing.c \
	main.c

OBJS=$(SRCS:.c=.o)

RM = rm -f

CC = clang

CFLAGS = -Wall -Wextra -Werror -I./libft/includes -I./ft_printf/includes -ggdb3

$(NAME) : $(OBJS)
	@$(MAKE) --directory ./libft > /dev/null 2>&1
	@$(MAKE) --directory ./ft_printf > /dev/null 2>&1
	@$(CC) $(CFLAGS) $(OBJS) ./libft/libft.a ./ft_printf/libftprintf.a -o $@ && echo "\033[32;1mSuccessful compilation !\033[0m"
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ > /dev/null 2>&1

clean: 
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re 


