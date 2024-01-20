/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:43:41 by tebandam          #+#    #+#             */
/*   Updated: 2024/01/19 14:48:28 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	ft_sort_two(t_list **stack_a)
{
	t_list	*current;

	current = *stack_a;
	if (current->content > current->next->content)
	{
		ft_swap_stack(stack_a, 'a');
	}
}

void	ft_sort_three(t_list **stack_a)
{
	t_list	*current;

	if (is_sorted(*stack_a))
		return ;
	current = *stack_a;
	ft_normalisation(*stack_a);
	if (current->rank == 1 && current->next->rank == 0)
	{
		ft_swap_stack(stack_a, 'a');
	}
	else if (current->rank == 2 && current->next->rank == 1)
	{
		ft_swap_stack(stack_a, 'a');
		ft_reverse_rotate(stack_a, 'a');
	}
	else if (current->rank == 2 && current->next->rank == 0)
		ft_rotate(stack_a, 'a');
	else if (current->rank == 0 && current->next->rank == 2)
	{
		ft_swap_stack(stack_a, 'a');
		ft_rotate(stack_a, 'a');
	}
	else if (current->rank == 1 && current->next->rank == 2)
		ft_reverse_rotate(stack_a, 'a');
}

void	ft_sort_five(t_list **stack_a, t_list **stack_b)
{
	int	i;

	i = 5;
	if (is_sorted(*stack_a))
		return ;
	while (i > 3)
	{
		if ((*stack_a)->rank == 0 || (*stack_a)->rank == 1)
		{
			ft_push(stack_b, stack_a, 'b');
			i--;
		}
		else
			ft_rotate(stack_a, 'a');
	}
	ft_sort_three(stack_a);
	if (*stack_b && (*stack_b)->next
		&& (*stack_b)->rank < (*stack_b)->next->rank)
	{
		ft_swap_stack(stack_b, 'b');
	}
	ft_push(stack_a, stack_b, 'a');
	ft_push(stack_a, stack_b, 'a');
}
