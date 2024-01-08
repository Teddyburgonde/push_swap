/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 12:59:13 by tebandam          #+#    #+#             */
/*   Updated: 2024/01/08 18:52:27 by tebandam         ###   ########.fr       */
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
	//ft_butterfly(&a, &b, 8);
	ft_sort(&a, &b);
	ft_free_list(a);
	ft_free_list(b);
	a = NULL;
	b = NULL;
}

// void	ft_sort(t_list **stack_a, t_list **stack_b)
// {
// 	int	pos;
// 	int	max;

// 	while (*stack_b != NULL)
// 	{
// 		max = ft_lstsize(*stack_b) - 1;
// 		pos = find_pos_highest_value(*stack_b, max);
// 		if (pos > ft_lstsize(*stack_b) / 2)
// 		{
// 			while ((*stack_b)->rank != max)
// 				ft_reverse_rotate(stack_b, 'b');
// 		}
// 		else
// 			while ((*stack_b)->rank != max)
// 				ft_rotate(stack_b, 'b');
// 		ft_push(stack_a, stack_b, 'a');
// 	}
// }

void	ft_sort_two(t_list **stack_a)
{
	t_list	*current;
	
	current = *stack_a;
	if (current->content > current->next->content)
	{
		ft_swap_stack(stack_a, 'a');
	}
}

void	ft_sort_three(t_list **stack_a)
{
	t_list	*current;

	current = *stack_a;
	if (current->content > current->next->content)
	{
		ft_swap_stack(stack_a, 'a');
	}
	if (current->next->content > current->next->next->content)
	{
		ft_rotate(stack_a, 'a');
		ft_swap_stack(stack_a, 'a');
		ft_reverse_rotate(stack_a, 'a');
	}
	if (current->content > current->next->content)
	{
		ft_swap_stack(stack_a, 'a');
	}
}


static void	sorting_choices(t_list *stack_a, t_list *stack_b, int size)
{
	(void)stack_b;
    if (size == 2)
        ft_sort_two(&stack_a);
    else if (size == 3)
        ft_sort_three(&stack_a);
	/*
    else if (size == 4)
        main_sort(stack_a, stack_b, 1, size - 1);
    else if (size == 5)
        sort_five(stack_a, stack_b);
    else if (size >= 6 && size <= 100)
        main_sort(stack_a, stack_b, 3, size - 1);
    else if (size > 100 && size <= 200)
        main_sort(stack_a, stack_b, 4, size - 1);
    else if (size > 200 && size <= 300)
        main_sort(stack_a, stack_b, 5, size - 1);
    else if (size > 300 && size <= 400)
        main_sort(stack_a, stack_b, 6, size - 1);
    else
        main_sort(stack_a, stack_b, 8, size - 1);
	*/
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
	//functions_call(a, b);
	sorting_choices(a, b, 3);
	return (0);
}
