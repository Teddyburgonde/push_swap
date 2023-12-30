/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 12:59:13 by tebandam          #+#    #+#             */
/*   Updated: 2023/12/30 16:41:30 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/includes/libftprintf.h"
#include "push_swap.h"


// pa (push a) : Takes the first element at the top of b and puts it on a.
// Does nothing if b is empty.

int *pa(int *tab_a, int *tab_b, int size, char a)
{
	
	ft_printf("p%c\n", a);
}

int	main(void)
{
	int	tab_a[] = {2, 9, 1, 8};
	int	tab_b[] = {3, 5, 8, 9};
	int	size;
	int	i;
	int	j;

	size = 4;
	i = 0;
	j = 0;
	ft_ss(tab_a, tab_b, size, 's');
	while (i < 4)
	{
		ft_printf("%d\n", tab_a[i]);
		i++;
	}
	ft_printf("\n");
	i = 0;
	while (i < 4)
	{
		ft_printf("%d\n", tab_b[i]);
		i++;
	}
	return (0);
}
