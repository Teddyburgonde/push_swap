/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 13:36:06 by tebandam          #+#    #+#             */
/*   Updated: 2024/01/19 11:04:27 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_swap_stack(t_list **stack, char c)
{
	t_list	*tmp_node;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	tmp_node = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	tmp_node->next = *stack;
	(*stack) = tmp_node;
	if (c != 'x')
		ft_printf("s%c\n", c);
	return (0);
}

void	ft_swap_ss(t_list **stack_a, t_list **stack_b, char c)
{
	ft_swap_stack(stack_a, c);
	ft_swap_stack(stack_b, 'x');
}
