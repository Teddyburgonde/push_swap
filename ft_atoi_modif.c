/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_modif.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:32:59 by tebandam          #+#    #+#             */
/*   Updated: 2024/01/17 16:59:51 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/includes/libftprintf.h"
#include "./libft/includes/libft.h"
#include "push_swap.h"

void	message_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

static int	is_whitespace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

#include <stdlib.h>

int	ft_atol_modif(char *nptr, t_list **stack_a, char **cut_argv)
{
	int	i;
	long	a;
	int	sign;

	i = 0;
	a = 0;
	sign = 1;
	while (is_whitespace(nptr[i]))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i + 1] == '+')
		{
			ft_free_list(*stack_a);
			ft_free_tab_2d(cut_argv);
			message_error();
		}
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
		a = a * 10 + (nptr[i++] - '0');
	a *= sign;
	if (!(a > -2147483649 && a < 2147483648))
	{
		ft_free_list(*stack_a);
		ft_free_tab_2d(cut_argv);
		message_error();
	}
	if (nptr[i] != '\0')
	{
		ft_free_list(*stack_a);
		ft_free_tab_2d(cut_argv);
		message_error();
	}
	return (a);
}
