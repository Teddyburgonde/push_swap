/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 12:59:13 by tebandam          #+#    #+#             */
/*   Updated: 2023/12/31 15:57:40 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/includes/libftprintf.h"
#include "./libft/includes/libft.h"
#include "./push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*node;
	t_list	*a;
	int		i;

	a = NULL;
	i = 1;
	while (i < argc)
	{
		node = ft_lstnew(ft_atoi(argv[i]));
		ft_lstadd_back(&a, node);
		i++;
	}
	ft_print_list(a);
	ft_free_list(a);
}
