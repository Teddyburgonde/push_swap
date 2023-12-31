/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 12:59:13 by tebandam          #+#    #+#             */
/*   Updated: 2023/12/31 13:48:28 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/includes/libftprintf.h"
#include "./libft/includes/libft.h"


void	ft_print_list(t_list *list)
{
	while (list != NULL)
	{
		ft_printf("%d\n", list->content);
		list = list->next;
	}
}

int	main()
{
	t_list *list;
	list = NULL;

	t_list *node1;
	t_list *node2;
	node1 = ft_lstnew(10);
	node2 = ft_lstnew(60);
	ft_lstadd_back(&list, node1);
	ft_lstadd_back(&list, node2);
	ft_print_list(list);

	free(node1);
	free(node2);
}
