/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 13:12:11 by tebandam          #+#    #+#             */
/*   Updated: 2024/01/01 14:10:38 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/includes/libftprintf.h"
# include "./libft/includes/libft.h"

# include <stdlib.h>

void	ft_print_list(t_list *list);
void	ft_free_list(t_list *lst);
int		ft_sawp_stack(t_list **stack, char c);

#endif
