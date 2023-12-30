/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ss.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 16:36:32 by tebandam          #+#    #+#             */
/*   Updated: 2023/12/30 16:41:41 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/includes/libftprintf.h"

//ss (swap ss): sa and sb.
int	*ft_ss(int *tab_a, int *tab_b, int size, char s)
{
	int	tmp;

	if (size >= 2)
	{
		tmp = tab_a[0];
		tab_a[0] = tab_a[1];
		tab_a[1] = tmp;
		tmp = tab_b[0];
		tab_b[0] = tab_b[1];
		tab_b[1] = tmp;
		ft_printf("s%c\n", s);
	}
	return (tab_a);
}