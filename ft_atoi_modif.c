/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_modif.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:32:59 by tebandam          #+#    #+#             */
/*   Updated: 2024/01/13 15:30:32 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/includes/libftprintf.h"
#include "./libft/includes/libft.h"

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

int	ft_atol_modif(const char *nptr)
{
	int	i;
	long	a;
	int	sign;

	i = 0;
	a = 0;
	sign = 1;
	while (is_whitespace(nptr[i]))
		i++;
	while (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i + 1] == '+')
			message_error();
		if (nptr[i] == '-')
			sign *= -1;
		if (nptr[i + 1] == '-')
			message_error();
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
		a = a * 10 + (nptr[i++] - '0');
	if (a > 2147483647 || a < -2147483648)
		message_error();
	if (nptr[i] != '\0')
		message_error();
	return ((int)a * sign);
}
