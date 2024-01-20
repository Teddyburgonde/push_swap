/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalisation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:37:08 by tebandam          #+#    #+#             */
/*   Updated: 2024/01/19 11:06:46 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_normalisation(t_list *a)
{
	t_list	*save;
	t_list	*current;
	int		count;

	count = 0;
	save = a;
	current = a;
	while (save)
	{
		count = 0;
		while (current)
		{
			if (save->content > current->content)
				count++;
			current = current->next;
		}
		save->rank = count;
		save = save->next;
		current = a;
	}
}
