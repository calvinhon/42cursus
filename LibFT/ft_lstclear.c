/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chon <chon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:55:15 by chon              #+#    #+#             */
/*   Updated: 2023/12/13 16:40:03 by chon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	if (lst == NULL || *lst == NULL)
		return ;
	if ((*lst)->next == NULL)
		{
			del(*lst);
			free(*lst);
			*lst = NULL;
			return ;
		}
	else
		ft_lstclear(&((*lst)->next), del);
}
