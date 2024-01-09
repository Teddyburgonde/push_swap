/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 12:59:13 by tebandam          #+#    #+#             */
/*   Updated: 2024/01/09 17:26:59 by tebandam         ###   ########.fr       */
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

void	functions_call_butterfly(t_list *a, t_list *b)
{
	check_duplicates(a);
	ft_normalisation(a);
	ft_butterfly(&a, &b, 8);
	ft_sort(&a, &b);
	//ft_free_list(a);
	//ft_free_list(b);
	//a = NULL;
	//b = NULL;
}

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
t_list	*find_smallest(t_list *stack)
{
	t_list	*smallest_node;
	t_list	*head;
	long			smallest;

	if (!stack)
		return (NULL);
	head = stack;
	smallest = 2147483648;
	while (head)
	{
		if (head->content < smallest)
		{
			smallest = head->content;
			smallest_node = head;
		}
		head = head->next;
	}
	return (smallest_node);
}

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

void	little_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*smallest;
	t_list	*head_a;

	if (!stack_a || !stack_b)
		return ;
	head_a = *stack_a;
	while (ft_lstsize(head_a) > 3)
		head_a = head_a->next;
	smallest = find_smallest(head_a);
	while (ft_lstsize(stack_a) > 3 && !is_sorted(stack_a))
	{
		if ((*stack_a)->next == smallest && *stack_a != find_smallest(stack_a))
			ft_rotate(stack_a, 'a');
		else
		{
			// a faire demain ! 
			init_stack_utils_b(a, b);
			finish_rotation(a, find_smallest(*a), 'a');
			push_b(b, a);
		}
	}
}

static void	sorting_choices(t_list *stack_a)
{
	int	size;
	
	size = ft_lstsize(stack_a);
    if (size == 2)
        ft_sort_two(&stack_a);
    else if (size == 3)
        ft_sort_three(&stack_a);
    else if (size == 5)
		ft_sort_for(&stack_a);
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
		if (!cut_argv)
			return (0);
		parse_arguments(&a, cut_argv);
		ft_free_tab_2d(cut_argv);
		cut_argv = NULL;
		i++;
	}
	ft_printf("Before sorting:\n");
	ft_print_list(a);
	if (ft_lstsize(a) >= 10)
	{
    	functions_call_butterfly(a, b);
	}
	else
	{	
    	sorting_choices(a);
	}
}
