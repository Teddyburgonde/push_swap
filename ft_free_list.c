/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:54:16 by tebandam          #+#    #+#             */
/*   Updated: 2024/01/01 14:05:43 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/includes/libft.h"

void	ft_free_list(t_list *lst)
{
	t_list	*temp;

	while (lst != NULL)
	{
		temp = lst;
		lst = lst->next;
		free(temp);
	}
}
