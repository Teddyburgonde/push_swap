/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 08:18:20 by tebandam          #+#    #+#             */
/*   Updated: 2024/01/02 14:36:14 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/includes/libftprintf.h"
#include "./libft/includes/libft.h"

void	ft_rotate(t_list **stack, char c)
{
	t_list	*tmp;
	t_list	*current;

	tmp = *stack;
	*stack = (*stack)->next;
	current = *stack;
	while (current->next)
	{
		current = current->next;
	}
	tmp->next = NULL;
	current->next = tmp;
	ft_printf("r%c\n", c);
}

void	ft_rotate_no_char(t_list **stack)
{
	t_list	*tmp;
	t_list	*current;

	tmp = *stack;
	*stack = (*stack)->next;
	current = *stack;
	while (current->next)
	{
		current = current->next;
	}
	tmp->next = NULL;
	current->next = tmp;
}

void	ft_rotate_a_b(t_list **stack_a, t_list **stack_b, char c)
{
	ft_rotate(stack_a, c);
	ft_rotate_no_char(stack_b);
}

void	ft_reverse_rotate(t_list **stack, char c)
{
	t_list	*current;
	t_list	*second_last;

	current = *stack;
	while (current->next->next != NULL)
	{
		current = current->next;
	}
	second_last = current;
	current = current->next;
	current->next = *stack;
	second_last->next = NULL;
	*stack = current;
	ft_printf("rr%c\n", c);
}
