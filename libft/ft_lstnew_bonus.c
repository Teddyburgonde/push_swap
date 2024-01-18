/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:45:13 by tebandam          #+#    #+#             */
/*   Updated: 2024/01/18 11:56:56 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int content)
{
	t_list	*tmp;

	tmp = malloc(sizeof(t_list));
	if (!tmp)
	{
		return (NULL);
	}
	tmp->content = content;
	tmp->next = NULL;
	return (tmp);
}
