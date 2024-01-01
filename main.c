/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 12:59:13 by tebandam          #+#    #+#             */
/*   Updated: 2024/01/01 16:57:23 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/includes/libftprintf.h"
#include "./libft/includes/libft.h"
#include "./push_swap.h"

//ra (rotate a) : Décale d’une position vers le haut tous les élements de la pile a.
// Le premier élément devient le dernier.
// int	ft_push(t_list **stack_dst, t_list **stack_src, char c)
// {
// 	t_list	*head;

// 	if (ft_lstsize(*stack_dst) == 0
// 		|| ft_lstsize(*stack_src) == 0)
// 		return (-1);
// 	head = *stack_src;
// 	*stack_src = (*stack_src)->next;
// 	ft_lstadd_front(stack_dst, head);
// 	ft_printf("p%c\n", c);
// 	return (0);
// }

void	ft_rotate(t_list **stack, char c)
{
	//t_list *head;
	// t_list	*tmp;

	// tmp = *stack;
	// while ((*stack)->next != NULL)
	// {
	// 	stack = &(*stack)->next;
	// 	if ((*stack)->next == NULL)
	// 	{
	// 		(*stack)->next = tmp;
	// 	}
	// }
	// tmp->next = NULL;
	// ft_printf("r%c\n", c);
		t_list *tmp = *stack;
        *stack = (*stack)->next;

        t_list *current = *stack;
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