/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 08:18:20 by tebandam          #+#    #+#             */
/*   Updated: 2024/01/02 08:19:21 by tebandam         ###   ########.fr       */
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
