/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 13:36:06 by tebandam          #+#    #+#             */
/*   Updated: 2024/01/01 14:08:45 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/includes/libftprintf.h"
#include "./libft/includes/libft.h"

int	ft_sawp_stack(t_list **stack, char c)
{
	t_list	*tmp_node;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	tmp_node = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	tmp_node->next = *stack;
	(*stack) = tmp_node;
	ft_printf("s%c\n", c);
	return (0);
}
