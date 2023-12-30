/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 12:59:13 by tebandam          #+#    #+#             */
/*   Updated: 2023/12/30 18:18:48 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/includes/libftprintf.h"
#include "push_swap.h"


// pa (push a) : Takes the first element at the top of b and puts it on a.
// Does nothing if b is empty.

void ft_pa(int *tab_a, int *tab_b, int size)
{
	int	i;
	
	i = size;
	if (size >= 2)
	{
		while (i > 0)
		{
			tab_a[i] = tab_a[i - 1];
			i--;
		}
		tab_a[0] = tab_b[0];
	}
	ft_printf("pa\n");
}

int	main(void)
{
	int	tab_a[] = {3, 1, 2, 6};
	int	tab_b[] = {9, 5, 8, 4};
	int	size;
	int	i;

	size = 4;
	i = 0;
	ft_pa(tab_a, tab_b, size);
	while (i <= size)
	{
		ft_printf("%d\n", tab_a[i]);
		i++;
	}
	return (0);
}
