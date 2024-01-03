/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 12:59:13 by tebandam          #+#    #+#             */
/*   Updated: 2024/01/03 17:20:17 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/includes/libftprintf.h"
#include "./libft/includes/libft.h"
#include "./push_swap.h"

static int	is_whitespace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	ft_atoi_modif(const char *nptr)
{
	int	i;
	int	a;
	int	sign;

	i = 0;
	a = 0;
	sign = 1;
	while (is_whitespace(nptr[i]))
		i++;
	while (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i + 1] == '+')
			return (0);
		if (nptr[i] == '-')
			sign *= -1;
		if (nptr[i + 1] == '-')
			return (0);
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		a = a * 10 + (nptr[i] - '0');
		i++;
	}
	if (nptr[i] != '\0')
    {
        ft_putstr_fd("Error\n", 2);
        exit(EXIT_FAILURE);
    }
	return (a * sign);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*node;
	char	**cut_argv;
	int		i;
	int		j;
	int		value;

	a = NULL;
	i = 1;
	j = 0;
	if (1 == argc || (2 == argc && !argv[1][0]))
	{
		ft_putstr_fd("Error\n", 2);
        exit(EXIT_FAILURE);
	}
	else if (2 == argc)
	{
		cut_argv = ft_split(argv[1], ' ');
		while (cut_argv[i - 1])
		{
			value = ft_atoi_modif(cut_argv[i - 1]);
			node = ft_lstnew(value);
			ft_lstadd_back(&a, node);
			i++;
		}
		while (cut_argv[j])
		{
			free(cut_argv[j]);
			j++;
		}
		free(cut_argv);
		argv = ft_split(argv[1], ' ');
	}
	else
	{
		while (i < argc)
		{
			value = ft_atoi_modif(argv[i]);
			node = ft_lstnew(value);
			ft_lstadd_back(&a, node);
			i++;
		}
	}
	ft_print_list(a);
	
	ft_free_list(a);
	a = NULL;
}
