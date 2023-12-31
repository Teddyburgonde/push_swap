/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 15:46:08 by tebandam          #+#    #+#             */
/*   Updated: 2024/01/05 17:36:31 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/includes/libftprintf.h"
#include "./libft/includes/libft.h"

void	ft_push(t_list **stack_dst, t_list **stack_src, char c)
{
	t_list	*head;

	head = *stack_src;
	*stack_src = (*stack_src)->next;
	ft_lstadd_front(stack_dst, head);
	ft_printf("p%c\n", c);
}
