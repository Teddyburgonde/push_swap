/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:35:54 by tebandam          #+#    #+#             */
/*   Updated: 2024/01/18 13:31:11 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/includes/libftprintf.h"
#include "./libft/includes/libft.h"

void	ft_print_list(t_list *list)
{
	t_list	*current;

	current = list;
	while (current)
	{
		ft_printf("%d\n", current->content);
		current = current->next;
	}
	
}
