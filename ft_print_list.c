#include "./libft/includes/libftprintf.h"
#include "./libft/includes/libft.h"

void	ft_print_list(t_list *list)
{
	t_list	*current;

	current = list;
	while (current)
	{
		ft_printf("%d\n", current->content);
		current = current->next;
	}
	
}
