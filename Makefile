NAME = push_swap

SRCS = ft_printf/ft_printf.c \
	ft_print_list.c \
	ft_free_list.c \
	ft_swap_stack.c \
	main.c

OBJS=$(SRCS:.c=.o)

RM = rm -f

CC = clang

CFLAGS = -Wall -Wextra -Werror -I./libft/includes -I./ft_printf/includes -g

$(NAME) : $(OBJS)
	@make -s --directory ./libft
	@make -s --directory ./ft_printf
	@$(CC) $(CFLAGS) $(OBJS) ./libft/libft.a ./ft_printf/libftprintf.a -o $@ -s && echo "\033[32;1mSuccessful compilation !\033[0m" || echo "\033[31;1mCompilation failed.\033[0m"
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean: 
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re 


