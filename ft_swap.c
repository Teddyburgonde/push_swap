/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 16:32:43 by tebandam          #+#    #+#             */
/*   Updated: 2023/12/30 16:38:25 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/includes/libftprintf.h"

//sa (swap a): Swaps the first 2 elements at the top of the a stack.
//Does nothing if there is only one or none.

//sb (swap b): Swaps the first 2 elements at the top of the b stack.
//Does nothing if there is only one or none.
int	*ft_swap(int *tab, int size, char c)
{
	int	tmp;

	if (size >= 2)
	{
		tmp = tab[0];
		tab[0] = tab[1];
		tab[1] = tmp;
		ft_printf("s%c\n", c);
	}
	return (tab);
}