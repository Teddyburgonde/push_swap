/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:55:32 by tebandam          #+#    #+#             */
/*   Updated: 2024/01/19 11:04:48 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	is_sorted(t_list *stack)
{
	int				data;
	t_list			*head;

	if (!stack)
		return (2);
	head = stack;
	data = head->content;
	while (head->next)
	{
		head = head->next;
		if (head->content < data)
			return (0);
		data = head->content;
	}
	return (1);
}

void	main_sort(t_list **stack_a, t_list **stack_b, int chunk)
{
	if (is_sorted(*stack_a))
		return ;
	ft_butterfly(stack_a, stack_b, chunk);
	ft_sort(stack_a, stack_b);
}

void	sorting_choices(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size == 2)
		ft_sort_two(stack_a);
	else if (size == 3)
		ft_sort_three(stack_a);
	else if (size == 4)
		main_sort(stack_a, stack_b, 1);
	else if (size == 5)
		ft_sort_five(stack_a, stack_b);
	else if (size >= 6 && size <= 100)
		main_sort(stack_a, stack_b, 3);
	else if (size > 100 && size <= 200)
		main_sort(stack_a, stack_b, 4);
	else if (size > 200 && size <= 300)
		main_sort(stack_a, stack_b, 5);
	else if (size > 300 && size <= 400)
		main_sort(stack_a, stack_b, 6);
	else
		main_sort(stack_a, stack_b, 8);
}

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
