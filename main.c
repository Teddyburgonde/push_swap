/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 12:59:13 by tebandam          #+#    #+#             */
/*   Updated: 2024/01/08 14:47:27 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/includes/libftprintf.h"
#include "./libft/includes/libft.h"
#include "./push_swap.h"

void parse_arguments(t_list **a, char **cut_argv)
{
    int j = 0;
    int value;
    t_list *node;

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

int main(int argc, char **argv)
{
    t_list  *a;
	t_list	*b;
	t_list	*current;
	t_list	*nextNode;
    char    **cut_argv;
    int     i;
    int     j;

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
    	j = 0;
        ft_free_tab_2d(cut_argv);
		cut_argv = NULL;
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
