/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_butterfly.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:59:50 by tebandam          #+#    #+#             */
/*   Updated: 2024/01/18 15:53:05 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/includes/libft.h"
#include "./push_swap.h"

void	ft_butterfly(t_list **stack_a, t_list **stack_b, int chunk)
{
	int	i;
	int	tracker;
	int	number_elements_in_chunk;
	int	len;

	len = ft_lstsize(*stack_a);
	number_elements_in_chunk = ft_lstsize(*stack_a) / chunk;
	tracker = number_elements_in_chunk;
	while (*stack_a != NULL)
	{
		i = 0;
		while (i < number_elements_in_chunk && *stack_a != NULL)
		{
			if ((*stack_a)->rank < tracker)
			{
				ft_push(stack_b, stack_a, 'b');
				if ((*stack_b)->rank > (tracker - len / (chunk * 2)))
					ft_rotate(stack_b, 'b');
				i++;
			}
			else
				ft_rotate(stack_a, 'a');
		}
		tracker += number_elements_in_chunk;
	}
}
