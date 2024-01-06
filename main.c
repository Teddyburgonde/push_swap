/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 12:59:13 by tebandam          #+#    #+#             */
/*   Updated: 2024/01/06 16:54:56 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/includes/libftprintf.h"
#include "./libft/includes/libft.h"
#include "./push_swap.h"

void	ft_butterfly(t_list **stack_a, t_list **stack_b, int chunk)
{
	int	i;
	int	tracker;
	int	number_elements_in_chunk;
	int	len;

	len = ft_lstsize(*stack_a);
	number_elements_in_chunk = ft_lstsize(*stack_a) / chunk;
	tracker = number_elements_in_chunk;
	while (*stack_a != NULL)
	{
		i = 0;
		while (i < number_elements_in_chunk && *stack_a != NULL)
		{
			if ((*stack_a)->rank < tracker)
			{
				ft_push(stack_b, stack_a, 'b');
				if ((*stack_b)->rank > (tracker - len / (chunk * 2))) 
					ft_rotate(stack_b, 'b');
				i++;
			}
			else
				ft_rotate(stack_a, 'a');
		}
		tracker += number_elements_in_chunk;
	}
}

int find_pos_highest_value(t_list *stack_b, int max)
{
	t_list	*current;
	int		highest_value;
	int		pos;

	pos = 0;
	highest_value = 0;
	current = stack_b;
	while (current && current->rank != max)
	{
		pos++;
		current = current->next;	
	}
	return (pos);
}

void	ft_sort(t_list **stack_a, t_list **stack_b)
{
	int	pos;
	int	max;

	while (*stack_b != NULL)
	{
		max = ft_lstsize(*stack_b) - 1;
		pos = find_pos_highest_value(*stack_b, max);
		if (pos > ft_lstsize(*stack_b) / 2)
		{
			while ((*stack_b)->rank != max)
				ft_reverse_rotate(stack_b, 'b');
		}
		else
			while ((*stack_b)->rank != max)
				ft_rotate(stack_b, 'b');
		ft_push(stack_a, stack_b, 'a');
	}
}

int main(int argc, char **argv)
{
    t_list  *a;
	t_list	*b;
    t_list  *node;
	t_list	*current;
	t_list	*nextNode;
    char    **cut_argv;
    int     i;
    int     j;
    int     value;

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
    	j = 0;
        while (cut_argv[j])
        {
            value = ft_atoi_modif(cut_argv[j]);
            node = ft_lstnew(value);
            ft_lstadd_back(&a, node);
            j++;
        }
        while (cut_argv[j])
        {
            free(cut_argv[j]);
            j++;
        }
        free(cut_argv);
		i++;
    }
	current = a;
	while (current)
	{
    	nextNode = current->next;
    	while (nextNode)
    	{
        	if (current->content == nextNode->content)
        	{
            	ft_putstr_fd("Error\n", 2);
            	exit(EXIT_FAILURE);
        	}
        	nextNode = nextNode->next;
    	}
    	current = current->next;
	}
	ft_normalisation(a);
	ft_butterfly(&a, &b, 8);
	ft_sort(&a, &b);
	//ft_print_list(b);
    ft_free_list(a);
	ft_free_list(b);
    a = NULL;
	b = NULL;
    return 0;
}

