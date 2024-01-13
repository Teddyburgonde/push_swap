/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:55:32 by tebandam          #+#    #+#             */
/*   Updated: 2024/01/13 14:34:03 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/includes/libft.h"
#include "./push_swap.h"

int	find_pos_highest_value(t_list *stack_b, int max)
{
	t_list	*current;
	int		highest_value;
	int		pos;

	pos = 0;
	highest_value = 0;
	current = stack_b;
	while (current && current->rank != max)
	{
		pos++;
		current = current->next;
	}
	return (pos);
}

void	ft_sort(t_list **stack_a, t_list **stack_b)
{
	int	pos;
	int	max;

	while (*stack_b != NULL)
	{
		max = ft_lstsize(*stack_b) - 1;
		pos = find_pos_highest_value(*stack_b, max);
		if (pos > ft_lstsize(*stack_b) / 2)
		{
			while ((*stack_b)->rank != max)
				ft_reverse_rotate(stack_b, 'b');
		}
		else
			while ((*stack_b)->rank != max)
				ft_rotate(stack_b, 'b');
		ft_push(stack_a, stack_b, 'a');
	}
}
