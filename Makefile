NAME = push_swap

SRCS = ft_printf/ft_printf.c \
	ft_swap.c \
	ft_ss.c \
main.c

OBJS=$(SRCS:.c=.o)

RM = rm -f

CC = clang

CFLAGS = -Wall -Wextra -Werror -I./libft/includes -I./ft_printf/includes -g

$(NAME) : $(OBJS)
	make --directory ./libft
	make --directory ./ft_printf
	$(CC) $(CFLAGS) $(OBJS) ./libft/libft.a ./ft_printf/libftprintf.a -o $@
	@echo "              _                 __                 ";
	@echo "      __.--**\"\"\"**--...__..--**\"\"\"*-.            "; 
	@echo "    .'                                \`-.         "; 
	@echo "  .'                         _           \        "; 
	@echo " /                         .'        .    \   _._ "; 
	@echo ":                         :          :\`*.  :-'.' ;"; 
	@echo ";    \`                    ;          \`.) \   /.-' "; 
	@echo ":     \`                             ; ' -*   ;    "; 
	@echo "       :.    \           :       :  :        :    "; 
	@echo " ;     ; `.   `.         ;     \` |  '             "; 
	@echo " |         `.            `. -*\"*\; /        :     "; 
	@echo " |    :     /\`-.           \`.    \/\`.'  _    \`.  "; 
	@echo ":    ;    :    \`*-.__.-*\"\"\":\`.   \ ;  'o\` \`. /   "; 
	@echo "       ;   ;                ;  \   ;:       ;:   ,/"; 
	@echo "  |  | | \033[32;1mSTOP AU BRACONNAGE !\033[0m"; 
	@echo "  \`  : :  :                /  /    | : .    ._.-'  "; 
	@echo "   \  \ ,  \              :   \`.   :  \ \   .'     "; 
	@echo "    :  *:   ;             :    |\`*-'   \`*+-*       ";
	@echo "    \`**-*\`\"\"               *---*                  "; 
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re 


