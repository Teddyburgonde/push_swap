/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 13:12:11 by tebandam          #+#    #+#             */
/*   Updated: 2024/01/17 16:57:47 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/includes/libftprintf.h"
# include "./libft/includes/libft.h"

# include <stdlib.h>

void	ft_print_list(t_list *list);
void	ft_free_list(t_list *lst);
int		ft_swap_stack(t_list **stack, char c);
void	ft_swap_ss(t_list **stack_a, t_list **stack_b, char c);
void	ft_push(t_list **stack_dst, t_list **stack_src, char c);
void	ft_rotate(t_list **stack, char c);
void	ft_rotate_no_char(t_list **stack);
void	ft_rotate_a_b(t_list **stack_a, t_list **stack_b, char c);
void	ft_reverse_rotate(t_list **stack, char c);
void	ft_reverse_rotate_no_char(t_list **stack);
void	ft_reverse_rotate_a_b(t_list **stack_a, t_list **stack_b, char c);
void	message_error(void);
void	ft_normalisation(t_list *a);
int		ft_atol_modif(char *nptr, t_list **stack_a, char **cut_argv);
void	ft_sort(t_list **stack_a, t_list **stack_b);
int		find_pos_highest_value(t_list *stack_b, int max);
void	ft_butterfly(t_list **stack_a, t_list **stack_b, int chunk);
void	ft_free_tab_2d(char **tab);

#endif
