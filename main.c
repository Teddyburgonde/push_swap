/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 12:59:13 by tebandam          #+#    #+#             */
/*   Updated: 2024/01/18 17:25:29 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/includes/libftprintf.h"
#include "./libft/includes/libft.h"
#include "./push_swap.h"

void	ft_free_tab_2d(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	is_sorted(t_list *stack)
{
	int				data;
	t_list			*head;

	if (!stack)
		return (2);
	head = stack;
	data = head->content;
	while (head->next)
	{
		head = head->next;
		if (head->content < data)
			return (0);
		data = head->content;
	}
	return (1);
}

int	ft_no_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	char	**cut_argv;
	t_list	*a;
	t_list	*b;
	int		i;

	a = NULL;
	b = NULL;
	i = 1;
	if (argc == 1 || ft_parsing_for_error(argv) == 1)
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	while (i < argc)
	{
		cut_argv = ft_split(argv[i], ' ');
		parse_arguments(&a, cut_argv);
		ft_free_tab_2d(cut_argv);
		i++;
	}
	ft_normalisation(a);
	check_duplicates(a);
	sorting_choices(&a, &b);
	ft_free_list(a);
	ft_free_list(b);
}
