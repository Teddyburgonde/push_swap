/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:03:39 by tebandam          #+#    #+#             */
/*   Updated: 2024/01/19 13:48:56 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	ft_parsing_for_error(char **tab)
{
	int	i;
	int	j;

	j = 1;
	while (tab[j])
	{
		i = 0;
		while (tab[j][i])
		{
			if (tab[j][i] == '+' || tab[j][i] == '-')
			{
				if (!ft_isdigit(tab[j][i + 1]))
					return (1);
			}
			if (tab[j][0] == 32 && (tab[j][1] == 32 || tab[j][1] == '\0'))
				return (1);
			i++;
		}
		if (i == 0)
			return (1);
		j++;
	}
	return (0);
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
				ft_free_list(list);
				exit(EXIT_FAILURE);
			}
			next_node = next_node->next;
		}
		current = current->next;
	}
}

void	parse_arguments(t_list **a, char **cut_argv)
{
	t_list	*node;
	int		j;
	int		value;

	j = 0;
	while (cut_argv[j])
	{
		value = ft_atol_modif(cut_argv[j], a, cut_argv);
		node = ft_lstnew(value);
		ft_lstadd_back(a, node);
		j++;
	}
}
