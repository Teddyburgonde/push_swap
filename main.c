/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 12:59:13 by tebandam          #+#    #+#             */
/*   Updated: 2024/01/17 17:00:57 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/includes/libftprintf.h"
#include "./libft/includes/libft.h"
#include "./push_swap.h"

void	ft_free_tab_2d(char **tab)
{
	int	i;

	if (!tab)
		return;

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
	int	value;

	j = 0;
	while (cut_argv[j])
	{
		value = ft_atol_modif(cut_argv[j], a, cut_argv);
		node = ft_lstnew(value);
		ft_lstadd_back(a, node);
		j++;
	}
	//ft_free_list(*a);
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

void	ft_sort_two(t_list **stack_a)
{
	t_list	*current;
	
	current = *stack_a;
	if (current->content > current->next->content)
	{
		ft_swap_stack(stack_a, 'a');
		ft_free_list(current);
	}
}

void	ft_sort_three(t_list **stack_a)
{
	t_list	*current;
	if (is_sorted(*stack_a))
	{
		return ;
	}
	current = *stack_a;
	ft_normalisation(*stack_a);
	if (current->rank == 1 && current->next->rank == 0)
	{
		ft_swap_stack(stack_a, 'a');
	}
	else if (current->rank == 2 && current->next->rank == 1)
	{
		ft_swap_stack(stack_a, 'a');
		ft_reverse_rotate(stack_a, 'a');
	}
	else if (current->rank == 2 && current->next->rank == 0)
	{	
		ft_rotate(stack_a, 'a');
	}
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
    while (i > 3) 
	{
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
	ft_free_list(*stack_a);
	ft_free_list(*stack_b);
}

void	main_sort(t_list *stack_a, t_list *stack_b, int chunk)
{
	if (is_sorted(stack_a))
	{
		return ;
	}
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


static int	ft_parsing_for_error(char **tab)
{
	
	int	i;
	int	j;

	j = 1;
	while (tab[j])
	{
		i = 0;
		while(tab[j][i])
		{
			if (tab[j][i] == '+' || tab[j][i] == '-')
			{
				if (!ft_isdigit(tab[j][i + 1]))
				{
					return (1);
				}			
			}
			if (tab[j][0] == 32 && (tab[j][1] == 32 || tab[j][1] == '\0'))
			{
				return (1);
			}
			i++;
		}
		if (i == 0)
			return (1);
		j++;
	}
	return (0);
}

// gestion des espaces
// doublons 

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
// int	ft_double(char *str)
// {
// 	int i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == str[i + 1])
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }
int	ft_countains_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i + 1] == ' ')
			return (1);
		i++;
	}
	return (0);
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
	i = 1;
	while (i < argc)
	{
		cut_argv = ft_split(argv[i], ' ');
		parse_arguments(&a, cut_argv);
		ft_free_tab_2d(cut_argv);
		i++;
	}
	ft_normalisation(a);
	check_duplicates(a);
    sorting_choices(a, b);
	//ft_free_list(a);
	ft_free_list(a);
	ft_free_list(b);
	//a = NULL;
	//b = NULL;
	//ft_print_list(a);
}