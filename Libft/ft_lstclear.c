/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:36:59 by hkarrach          #+#    #+#             */
/*   Updated: 2023/11/20 17:38:16 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstdelone(t_list *lst, void (*del)(void*))
{
	t_list *curr;
	t_list *tmp;

	if(!lst || !del)
		return ;
	curr = *lst;
	while(curr)
	{
		tmp = curr;
		curr = curr->next;
		del(tmp->content);
		free(tmp);
	}
	*lst = NULL;
}
