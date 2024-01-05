/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 12:59:13 by tebandam          #+#    #+#             */
/*   Updated: 2024/01/05 17:54:47 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/includes/libftprintf.h"
#include "./libft/includes/libft.h"
#include "./push_swap.h"

void	ft_bufferfly(t_list *stack_a, t_list *stack_b, int chunk)
{
	int	i;
	int	tracker;
	int	number_elements_in_chunk;
	int	len;

	len = ft_lstsize(stack_a);
	number_elements_in_chunk = ft_lstsize(stack_a) / chunk;
	// tracker la plus grande valeur des elements du premier chunk
	tracker = number_elements_in_chunk;
	while (stack_a != NULL)
	{
		i = 0;
		while (i < number_elements_in_chunk && stack_a != NULL)
		{
			if (stack_a->rank < tracker)
			{
				ft_push(&stack_b, &stack_a, 'b');
				// permet de rendre l'algorithme optimiser (pivot)
				// si la valeur que je viens de push
				// dans la stadck_b est plus grand que le pivot on rotate
				if (stack_b->rank > (tracker - len / (chunk * 2))) {
					ft_rotate(&stack_b, 'b');
				}
				i++;
			}
			else
				ft_rotate(&stack_a, 'a');
		}
		tracker += number_elements_in_chunk;
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
	ft_bufferfly(a, b, 8);
    
	//ft_print_list(a);
	
    ft_free_list(a);
	ft_free_list(b);
    a = NULL;
	b = NULL;
    return 0;
}

