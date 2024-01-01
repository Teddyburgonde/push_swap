/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 12:59:13 by tebandam          #+#    #+#             */
/*   Updated: 2024/01/01 17:28:03 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/includes/libftprintf.h"
#include "./libft/includes/libft.h"
#include "./push_swap.h"

void	ft_rotate(t_list **stack, char c)
{
	t_list *tmp;
	t_list *current;
	
	tmp = *stack;
	*stack = (*stack)->next;
	current  = *stack;
	while (current->next)
	{
		current = current->next;
	}
	tmp->next = NULL;
	current->next = tmp;
	ft_printf("r%c\n", c);
}


int	main()
{
	t_list *a;
	//t_list *b;
	t_list *node1;
	t_list *node2;
	t_list *node3;
	
	// t_list *node1b;
	// t_list *node2b;
	// t_list *node3b;

	a = NULL;
	//b = NULL;

	node1 = ft_lstnew(10);
	node2 = ft_lstnew(20);
	node3 = ft_lstnew(50);

	// node1b = ft_lstnew(60);
	// node2b = ft_lstnew(70);
	// node3b = ft_lstnew(80);


	ft_lstadd_back(&a, node1);
	ft_lstadd_back(&a, node2);
	ft_lstadd_back(&a, node3);

	// ft_lstadd_back(&b, node1b);
	// ft_lstadd_back(&b, node2b);
	// ft_lstadd_back(&b, node3b);
	ft_printf("La liste a: \n");
	ft_rotate(&a, 'a');
	ft_print_list(a);
	// ft_printf("\n");
	// ft_printf("La liste b: \n");
	// ft_print_list(b);
	
	ft_free_list(a);
	//ft_free_list(b);
	a = NULL;
	//b = NULL;
}
