/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 13:12:11 by tebandam          #+#    #+#             */
/*   Updated: 2023/12/30 16:37:33 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_vars
{
	int *tab;
}	t_vars;


int	*ft_swap(int *tab, int size, char c);
int	*ft_ss(int *tab_a, int *tab_b, int size, char s);

#endif