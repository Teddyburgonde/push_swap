/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 15:46:08 by tebandam          #+#    #+#             */
/*   Updated: 2024/01/01 15:54:12 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/includes/libftprintf.h"
#include "./libft/includes/libft.h"

int	ft_push(t_list **stack_dst, t_list **stack_src, char c)
{
	t_list	*head;

	if (ft_lstsize(*stack_dst) == 0
		|| ft_lstsize(*stack_src) == 0)
		return (-1);
	head = *stack_src;
	*stack_src = (*stack_src)->next;
	ft_lstadd_front(stack_dst, head);
	ft_printf("p%c\n", c);
	return (0);
}
