/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkylee <minkylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 06:28:19 by minkylee          #+#    #+#             */
/*   Updated: 2024/01/20 13:05:45 by minkylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (lst == NULL)
		return ;
	temp = *lst;
	while (temp != NULL)
	{
		temp = *lst;
		del(temp->content);
		temp = temp -> next;
		free(*lst);
		*lst = temp;
	}
}
