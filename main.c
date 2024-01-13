/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 12:59:13 by tebandam          #+#    #+#             */
/*   Updated: 2024/01/13 15:42:59 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/includes/libftprintf.h"
#include "./libft/includes/libft.h"
#include "./push_swap.h"


int	is_sorted(t_list *stack)
{
	int				data;
	t_list	*head;

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

void	parse_arguments(t_list **a, char **cut_argv)
{
	t_list	*node;
	int		j;
	int		value;

	j = 0;
	while (cut_argv[j])
	{
		value = ft_atol_modif(cut_argv[j]);
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

// void	functions_call_butterfly(t_list *a, t_list *b)
// {
// 	check_duplicates(a);
// 	ft_normalisation(a);
// 	ft_butterfly(&a, &b, 8);
// 	ft_sort(&a, &b);
// 	ft_free_list(a);
// 	ft_free_list(b);
// 	a = NULL;
// 	b = NULL;
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
	if (is_sorted(*stack_a))
		return ;
	current = *stack_a;
	ft_normalisation(*stack_a);
	if (current->rank == 1 && current->next->rank == 0)
		ft_swap_stack(stack_a, 'a');
	else if (current->rank == 2 && current->next->rank == 1)
	{
		ft_swap_stack(stack_a, 'a');
		ft_reverse_rotate(stack_a, 'a');	
	}
	else if (current->rank == 2 && current->next->rank == 0)
		ft_rotate(stack_a, 'a');
	else if (current->rank == 0 && current->next->rank == 2)
	{
		ft_swap_stack(stack_a, 'a');
		ft_rotate(stack_a, 'a');
	}
	else if (current->rank == 1 && current->next->rank == 2)
		ft_reverse_rotate(stack_a, 'a');
}

void ft_sort_five(t_list **stack_a, t_list **stack_b) {
    int i = 5;

    if (is_sorted(*stack_a))
        return;
    while (i > 3) {
        if ((*stack_a)->rank == 0 || (*stack_a)->rank == 1) {
            ft_push(stack_b, stack_a, 'b');
            i--;
        } 
		else 
		{
            ft_rotate(stack_a, 'a');
        }
    }
    ft_sort_three(stack_a);
    if (*stack_b && (*stack_b)->next && (*stack_b)->rank < (*stack_b)->next->rank) {
        ft_swap_stack(stack_b, 'b');
    }
    ft_push(stack_a, stack_b, 'a');
    ft_push(stack_a, stack_b, 'a');
}

void	main_sort(t_list *stack_a, t_list *stack_b, int chunk)
{
	if (is_sorted(stack_a))
		return ;
	ft_butterfly(&stack_a, &stack_b, chunk);
	ft_sort(&stack_a, &stack_b);
}

static void	sorting_choices(t_list *stack_a, t_list *stack_b)
{
	int	size;

	size = ft_lstsize(stack_a);
    if (size == 2)
        ft_sort_two(&stack_a);
    else if (size == 3)
        ft_sort_three(&stack_a);
    else if (size == 4)
		main_sort(stack_a, stack_b, 1);
	else if (size == 5)
		ft_sort_five(&stack_a, &stack_b);
	else if (size >= 6 && size <= 100)
		main_sort(stack_a, stack_b, 3);
	else if (size > 100 && size <= 200)
		main_sort(stack_a, stack_b, 4);
	else if (size > 200 && size <= 300)
		main_sort(stack_a, stack_b, 5);
	else if (size > 300 && size <= 400)
		main_sort(stack_a, stack_b, 6);
	else
		main_sort(stack_a, stack_b, 8);
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
	if (1 == argc || (argv[1][0] == 0 && argv[1][1] == 0) || (argv[1][0] == 32 && argv[1][1] == 32) || (argv[1][0] == 32) || (argv[1][0] == 0) || (2 >= argc && !argv[1][0]) || (argv[1][0] == '+' && argv[1][1] == 32))
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	while (i < argc)
	{
		cut_argv = ft_split(argv[i], ' ');
		if (!cut_argv)
			return (0);
		parse_arguments(&a, cut_argv);
		ft_free_tab_2d(cut_argv);
		cut_argv = NULL;
		i++;
	}
	ft_normalisation(a);
    sorting_choices(a, b);
	ft_free_list(a);
	ft_free_list(b);
	a = NULL;
	b = NULL;
	//ft_print_list(a);
}