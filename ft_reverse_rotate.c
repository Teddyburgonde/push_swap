/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:02:09 by tebandam          #+#    #+#             */
/*   Updated: 2024/01/19 11:06:32 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_reverse_rotate_no_char(t_list **stack)
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
}

void	ft_reverse_rotate_a_b(t_list **stack_a, t_list **stack_b, char c)
{
	ft_reverse_rotate(stack_a, c);
	ft_reverse_rotate_no_char(stack_b);
}
