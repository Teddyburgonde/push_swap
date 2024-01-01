/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 12:59:13 by tebandam          #+#    #+#             */
/*   Updated: 2024/01/01 14:08:21 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/includes/libftprintf.h"
#include "./libft/includes/libft.h"
#include "./push_swap.h"

int	main()
{
	t_list *a;
	t_list *node1;
	t_list *node2;
	t_list *node3;

	a = NULL;

	node1 = ft_lstnew(10);
	node2 = ft_lstnew(20);
	node3 = ft_lstnew(50);

	ft_lstadd_back(&a, node1);
	ft_lstadd_back(&a, node2);
	ft_lstadd_back(&a, node3);
	
	// before
	ft_printf("Before:\n");
	ft_print_list(a);
	
	//after 
	ft_printf("After\n");
	ft_sawp_stack(&a, 'a');
	ft_print_list(a);
	ft_free_list(a);
	a = NULL;
}