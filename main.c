/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 12:59:13 by tebandam          #+#    #+#             */
/*   Updated: 2024/01/08 17:10:04 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/includes/libftprintf.h"
#include "./libft/includes/libft.h"
#include "./push_swap.h"

void	parse_arguments(t_list **a, char **cut_argv)
{
	t_list	*node;
	int		j;
	int		value;

	j = 0;
	while (cut_argv[j])
	{
		value = ft_atoi_modif(cut_argv[j]);
		node = ft_lstnew(value);
		ft_lstadd_back(a, node);
		j++;
	}
}

void	ft_free_tab_2d(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	check_duplicates(t_list *list)
{
	t_list	*current;
	t_list	*next_node;

	current = list;
	while (current)
	{
		next_node = current->next;
		while (next_node)
		{
			if (current->content == next_node->content)
			{
				ft_putstr_fd("Error\n", 2);
				exit(EXIT_FAILURE);
			}
			next_node = next_node->next;
		}
		current = current->next;
	}
}

void	functions_call(t_list *a, t_list *b)
{
	check_duplicates(a);
	ft_normalisation(a);
	ft_butterfly(&a, &b, 8);
	ft_sort(&a, &b);
	ft_free_list(a);
	ft_free_list(b);
	a = NULL;
	b = NULL;
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
	if (1 == argc || (2 >= argc && !argv[1][0]))
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	while (i < argc)
	{
		cut_argv = ft_split(argv[i], ' ');
		parse_arguments(&a, cut_argv);
		ft_free_tab_2d(cut_argv);
		cut_argv = NULL;
		i++;
	}
	functions_call(a, b);
	return (0);
}
